#pragma once

/**
 * @file verbosity.h
 * @brief Defines custom logging verbosity levels and provides integration with spdlog.
 * 
 * This header declares the ::nyxara::logging::Verbosity enumeration, which specifies
 * different levels of logging detail used throughout the application.
 * 
 * It also provides the ::nyxara::logging::to_spdlog_level function for converting
 * custom verbosity levels to the corresponding spdlog logging levels, enabling seamless
 * integration with the spdlog logging framework.
 * 
 * @details
 * The Verbosity levels range from ::nyxara::logging::Verbosity::Critical (for fatal errors)
 * to ::nyxara::logging::Verbosity::Trace (for fine-grained debug output), with
 * ::nyxara::logging::Verbosity::None disabling logging entirely.
 * 
 * These levels are used to filter which log messages are emitted at runtime,
 * based on the configured verbosity for a logging category or component.
 * 
 * @note if an invalid or ::nyxara::logging::Verbosity::None level is passed to
 * ::nyxara::logging::to_spdlog_level, it default to spdlog::level::off.
 */

#include <spdlog/spdlog.h>

namespace nyxara::logging
{
	/**
	 * @brief Represents the verbosity level of a log message.
	 * 
	 * These levels control which log messages are emitted based on the 
	 * configured threshold for a given logging category.
	 * 
	 * If a message's level is lower than the category's verbosity, it is skipped.
	 */
	enum class Verbosity
	{
		None = 0,	///< Logging disabled
		Critical,	///< Critical failures (non-recoverable)	
		Error,		///< Recoverable errors
		Warn,		///< Warnings that might require attention
		Info,		///< General information about application flow
		Debug,		///< Debug-level information for development
		Trace		///< Very detailed internal state (high-frequency)
	};

	/**
	 * @brief Converts a Verbosity level to its corresponding spdlog level.
	 * 
	 * @param level The Nyxara verbosity level.
	 * @return The equivalent spdlog level.
	 *
	 * If the level is Verbosity::None or invalid, spdlog::level::off is returned.
	 */
	constexpr spdlog::level::level_enum to_spdlog_level(Verbosity level) noexcept
	{
		switch (level) {
		case Verbosity::Critical: return spdlog::level::critical;
		case Verbosity::Error:	  return spdlog::level::err;
		case Verbosity::Warn:	  return spdlog::level::warn;
		case Verbosity::Info:	  return spdlog::level::info;
		case Verbosity::Debug:	  return spdlog::level::debug;
		case Verbosity::Trace:	  return spdlog::level::trace;
		default:				  return spdlog::level::off;
		}
	}
} // namespace nyxara::logging
