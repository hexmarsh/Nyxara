#pragma once
#include "nyxara/logging/function_tracer.h"
#include "nyxara/logging/logger.h"

#define NYX_DEFINE_LOG_CATEGORY(Name) static ::nyxara::logging::category Name(#Name)

#define NYX_SET_LOG_LEVEL(CAT, LEVEL) \
            ::nyxara::logging::logger::set_category_level(CAT, LEVEL)

#define NYX_LOG(CAT, LEVEL, ...) \
            ::nyxara::logging::logger::log(CAT, LEVEL, __VA_ARGS__)

// Convenience macros
#define NYX_LOG_CRITICAL(CAT, ...) NYX_LOG(CAT, ::nyxara::logging::verbosity::critical, __VA_ARGS__)
#define NYX_LOG_ERROR(CAT, ...) NYX_LOG(CAT, ::nyxara::logging::verbosity::error, __VA_ARGS__)
#define NYX_LOG_WARN(CAT, ...)  NYX_LOG(CAT, ::nyxara::logging::verbosity::warn,  __VA_ARGS__)
#define NYX_LOG_INFO(CAT, ...)  NYX_LOG(CAT, ::nyxara::logging::verbosity::info,  __VA_ARGS__)
#define NYX_LOG_DEBUG(CAT, ...) NYX_LOG(CAT, ::nyxara::logging::verbosity::debug, __VA_ARGS__)
#define NYX_LOG_TRACE(CAT, ...) NYX_LOG(CAT, ::nyxara::logging::verbosity::trace, __VA_ARGS__)
#define NYX_TRACE_FUNCTION(CAT) ::nyxara::logging::function_tracer tracer(CAT, __func__)

// Call depth management macros
#define NYX_LOG_ENABLE_CALL_DEPTH() ::nyxara::logging::logger::enable_call_depth(true)
#define NYX_LOG_DISABLE_CALL_DEPTH() ::nyxara::logging::logger::enable_call_depth(false)
