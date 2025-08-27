#pragma once

#include <spdlog/spdlog.h>

namespace Nyxara::Logging
{
	/**
	 * @brief Represents the verbosity level of a log message.
	 * 
	 * These levels control which log messages are emitted based on the 
	 * configured threshold for a given logging cateogry.
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
		Trace		///< Very detailed interal state (high-frequency)
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
} // namespace nyx::logging
