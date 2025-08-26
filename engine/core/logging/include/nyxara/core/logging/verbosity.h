#pragma once

#include <spdlog/spdlog.h>

namespace Nyxara::Logging
{
	enum class Verbosity
	{
		None = 0, Critical, Error, Warn, Info, Debug, Trace
	};

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
