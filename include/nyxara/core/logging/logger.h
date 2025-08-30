#pragma once

/**
 * @file logger.h
 * @brief Core logging interface for the Nyxara engine.
 *
 * This header defines the ::nyxara::logging::Logger class, which serves as the
 * central entry point for logging functionality in the Nyxara engine.
 *
 * It provides static methods for:
 * - Initializing the logging system
 * - Creating and managing loggers by category
 * - Logging messages at various verbosity levels
 * - Enabling or disabling call-depth tracking in logs
 *
 * Logging is typically organized by categories defined using macros or manually,
 * and can be filtered at runtime based on verbosity levels.
 * The system supports both eager and lazy initialization for flexibility.
 *
 * @details
 * Call-depth tracking is optional and can be toggled using
 * EnableCallDepth() and DisableCallDepth(), providing insight into nested
 * function calls or recursive logic.
 *
 * The Logger uses the spdlog backend for high-performance logging.
 *
 * @see nyxara::logging::Verbosity
 * @see nyxara::logging::Category
 * @see nyxara::logging::CallDepthManager
 */

#include <memory>
#include <shared_mutex>
#include <string>
#include <unordered_map>
#include "nyxara/core/logging/call_depth_manager.h"
#include "nyxara/core/logging/category.h"
#include "nyxara/core/logging/verbosity.h"

// forward declarations
namespace spdlog { class logger; }

namespace nyxara::logging
{
	/**
	 * @brief Core logging utility for the Nyxara engine.
	 *
	 * Provides a static interface for managing log categories, verbosity levels,
	 * and logging messages with optional call-depth metadata.
	 * 
	 * The logging system can be explicitly initialized by calling Init(),
	 * but it also supports lazy initialization. Loggers will automatically
	 * initialize themselves the first time they are used, even if Init()
	 * is not called manually.
	 */
	class Logger
	{
	public:
		/**
		 * @brief Initializes the logging system explicitly.
		 *
		 * This should be called once at application startup to pre-configure
		 * logging categories, sinks, and formatting.
		 * 
		 * If Init() is not called, the system will initialize itself
		 * on first use (lazy initialization).
		 */
		static void Init();

		/**
		 * @brief Sets the verbosity level for a specific logging category.
		 * 
		 * @param category The logging category.
		 * @param level The verbosity to assign.
		 */
		static void SetCategoryLevel(const Category& category, Verbosity level);

		/**
		 * @brief Logs a formatted message under the given category and verbosity.
		 * 
		 * Automatically checks the category's current verbosity level and skips logging
		 * if the level is too low. Also adds call depth information if call depth logging is enabled.
		 * 
		 * @tparam Args Variadic template arguments used for formatting.
		 * @param category The category under which to log the message.
		 * @param level The severity/verbosity level of the log.
		 * @param fmtStr A fmtlib-compatible format string.
		 * @param args Arguments to be formatted into the string.
		 */
		template<typename... Args>
		static void Log(const Category& category, Verbosity level, fmt::format_string<Args...> fmtStr, Args&&... args)
		{
			if (level == Verbosity::None)
			{
				return;
			}

			Verbosity categoryLevel = GetCategoryLevel(category.GetName());

			if (level > categoryLevel)
			{
				return;
			}

			auto loggerPtr = category.GetLogger();

			if (!loggerPtr->should_log(to_spdlog_level(level)))
			{
				return;
			}

			if (!CallDepthManager::IsEnabled())
			{
				loggerPtr->log(to_spdlog_level(level), fmtStr, std::forward<Args>(args)...);
				return;
			}

			// Format the depth prefix and message directly into buffer
			spdlog::memory_buf_t buffer;

			auto appender = fmt::appender(buffer);
			fmt::format_to(appender, "[depth: {}] ", CallDepthManager::GetDepth());
			fmt::format_to(appender, fmtStr, std::forward<Args>(args)...);

			loggerPtr->log(to_spdlog_level(level), fmt::string_view(buffer.data(), buffer.size()));
		}

		/**
		 * @brief Retrieves an existing logger or creates a new one.
		 * 
		 * If the logger does not exist yet, it will automatically be initialized.
		 * 
		 * @param name The name of the logger.
		 * @return A shared pointer to the logger.
		 */
		static std::shared_ptr<spdlog::logger> GetOrCreateLogger(const std::string& name);

		/**
		 * @brief Enables call-depth information for logging output.
		 */
		static void EnableCallDepth() { CallDepthManager::SetEnabled(true); }

		/**
		 * @brief Disables call-depth information for logging output.
		 */
		static void DisableCallDepth() { CallDepthManager::SetEnabled(false); }

		/**
		 * @brief Checks if call-depth information is currently enabled.
		 * 
		 * @return True if call-depth information is enabled, false otherwise.
		 */
		static bool IsCallDepthEnabled() { return CallDepthManager::IsEnabled(); }

	private:
		/**
		 * @brief Retrieves the configured verbosity level for a given category name.
		 * 
		 * @param cat_name The name of the category.
		 * @return The configured verbosity level.
		 */
		static Verbosity GetCategoryLevel(const std::string& cat_name);
	};
} // namespace nyxara::logging

