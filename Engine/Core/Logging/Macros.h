#pragma once
#include "Engine/Core/Logging/FunctionTracer.h"
#include "Engine/Core/Logging/Logger.h"

#define NYX_DEFINE_LOG_CATEGORY(Name) static ::Nyxara::Logging::Category Name(#Name)

#define NYX_SET_LOG_LEVEL(CAT, LEVEL) \
            ::Nyxara::Logging::Logger::SetCategoryLevel(CAT, LEVEL)

#define NYX_LOG(CAT, LEVEL, ...) \
            ::Nyxara::Logging::Logger::log(CAT, LEVEL, __VA_ARGS__)

// Convenience macros
#define NYX_LOG_CRITICAL(CAT, ...) NYX_LOG(CAT, ::Nyxara::Logging::Verbosity::Critical, __VA_ARGS__)
#define NYX_LOG_ERROR(CAT, ...) NYX_LOG(CAT, ::Nyxara::Logging::Verbosity::Error, __VA_ARGS__)
#define NYX_LOG_WARN(CAT, ...)  NYX_LOG(CAT, ::Nyxara::Logging::Verbosity::Warn,  __VA_ARGS__)
#define NYX_LOG_INFO(CAT, ...)  NYX_LOG(CAT, ::Nyxara::Logging::Verbosity::Info,  __VA_ARGS__)
#define NYX_LOG_DEBUG(CAT, ...) NYX_LOG(CAT, ::Nyxara::Logging::Verbosity::Debug, __VA_ARGS__)
#define NYX_LOG_TRACE(CAT, ...) NYX_LOG(CAT, ::Nyxara::Logging::Verbosity::Trace, __VA_ARGS__)
#define NYX_TRACE_FUNCTION(CAT) ::Nyxara::Logging::FunctionTracer tracer(CAT, __func__)

// Call depth management macros
#define NYX_LOG_ENABLE_CALL_DEPTH() ::Nyxara::Logging::Logger::EnableCallDepth(true)
#define NYX_LOG_DISABLE_CALL_DEPTH() ::Nyxara::Logging::Logger::EnableCallDepth(false)
