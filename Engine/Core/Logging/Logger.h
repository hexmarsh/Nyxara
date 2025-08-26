#pragma once
#include <memory>
#include <shared_mutex>
#include <string>
#include <unordered_map>

#include "Engine/Core/Logging/Category.h"
#include "Engine/Core/Logging/Verbosity.h"
#include "Engine/Core/Logging/CallDepthManager.h"

// forward declarations
namespace spdlog { class logger; }

namespace Nyxara::Logging
{
	class Logger
	{
	public:
		static void Init();
		static void SetCategoryLevel(const Category& category, Verbosity level);

		template<typename... Args>
		static void log(const Category& category, Verbosity level, fmt::format_string<Args...> fmtStr, Args&&... args) {
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

			// Avoid all allocations by formatting spaces and message directly into buffer
			spdlog::memory_buf_t buffer;

			auto appender = fmt::appender(buffer);
			fmt::format_to(appender, "{:{}}", "", CallDepthManager::GetIndentationCount());
			fmt::format_to(appender, fmtStr, std::forward<Args>(args)...);

			loggerPtr->log(to_spdlog_level(level), fmt::string_view(buffer.data(), buffer.size()));
		}

		static std::shared_ptr<spdlog::logger> GetOrCreateLogger(const std::string& name);

		// Call depth management for normal logging
		static void EnableCallDepth(bool enabled = true) { CallDepthManager::SetEnabled(enabled); }
		static bool IsCallDepthEnabled() { return CallDepthManager::IsEnabled(); }

	private:
		static Verbosity GetCategoryLevel(const std::string& cat_name);

		inline static std::unordered_map<std::string, Verbosity> CategoryLevels;
		inline static std::shared_mutex LevelsMutex;
		inline static bool bIsInitialized = false;
		inline static std::mutex InitMutex;
	};
} // namespace nyx::logging

