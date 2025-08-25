#pragma once
#include <spdlog/spdlog.h>

namespace nyxara::logging
{
	enum class verbosity
	{
		none = 0, critical, error, warn, info, debug, trace
	};

	constexpr spdlog::level::level_enum to_spdlog_level(verbosity level) noexcept
	{
		switch (level) {
		case verbosity::critical: return spdlog::level::critical;
		case verbosity::error:	  return spdlog::level::err;
		case verbosity::warn:	  return spdlog::level::warn;
		case verbosity::info:	  return spdlog::level::info;
		case verbosity::debug:	  return spdlog::level::debug;
		case verbosity::trace:	  return spdlog::level::trace;
		default:				  return spdlog::level::off;
		}
	}
} // namespace nyxara::logging
