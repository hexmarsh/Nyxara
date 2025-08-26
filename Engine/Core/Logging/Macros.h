#pragma once
#include "Engine/Core/Logging/FunctionTracer.h"
#include "Engine/Core/Logging/Logger.h"

#define NYX_DEFINE_LOG_CATEGORY_IMPL(Name) \
    static const ::Nyxara::Logging::Category& NYX_GET_LOG_CATEGORY_##Name() { \
        static const ::Nyxara::Logging::Category category(#Name); \
        return category; \
    }

#define NYX_DEFINE_LOG_CATEGORY(Name) \
    NYX_DEFINE_LOG_CATEGORY_IMPL(Name) \
    static const ::Nyxara::Logging::Category& Name = NYX_GET_LOG_CATEGORY_##Name()

#define NYX_GET_LOG_CATEGORY(Name) NYX_GET_LOG_CATEGORY_##Name()

#define NYX_DECLARE_LOG_CATEGORY(Name) \
    const ::Nyxara::Logging::Category& NYX_GET_LOG_CATEGORY_##Name(); \
    static const ::Nyxara::Logging::Category& Name = NYX_GET_LOG_CATEGORY_##Name()

#define NYX_SET_LOG_LEVEL(CAT, LEVEL) \
            ::Nyxara::Logging::Logger::SetCategoryLevel(CAT, LEVEL)

#define NYX_LOG(CAT, LEVEL, ...) \
            ::Nyxara::Logging::Logger::Log(CAT, LEVEL, __VA_ARGS__)

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
