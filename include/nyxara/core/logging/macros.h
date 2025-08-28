#pragma once

#include "nyxara/core/logging/function_tracer.h"
#include "nyxara/core/logging/logger.h"

/**
 * @defgroup LoggingMacros Nyxara Logging Macros 
 * @brief Useful macros for structured logging and function tracing.
 * @{
 */

/**
 * @def NYX_DEFINE_LOG_CATEGORY_IMPL(Name)
 * @brief Defines the internal function that returns a static logging category instance.
 * 
 * This is intended for internal use. Use NYX_DEFINE_LOG_CATEGORY instead.
 */
#define NYX_DEFINE_LOG_CATEGORY_IMPL(Name) \
    static const ::Nyxara::Logging::Category& NYX_GET_LOG_CATEGORY_##Name() { \
        static const ::Nyxara::Logging::Category category(#Name); \
        return category; \
    }

/**
 * @def NYX_DEFINE_LOG_CATEGORY(Name)
 * @brief Defines a static logging category with the given name.
 * 
 * This macros should be used in a .cpp file to define a new logging category.
 * 
 * @code
 * NYX_DEFINE_LOG_CATEGORY(Renderer)
 * @endcode
 */
#define NYX_DEFINE_LOG_CATEGORY(Name) \
    NYX_DEFINE_LOG_CATEGORY_IMPL(Name) \
    static const ::Nyxara::Logging::Category& Name = NYX_GET_LOG_CATEGORY_##Name()

/**
 * @def NYX_GET_LOG_CATEGORY(Name)
 * @brief Gets the reference to the logging category function for a given name.
 * 
 * Typically used internally by other macros.
 */
#define NYX_GET_LOG_CATEGORY(Name) NYX_GET_LOG_CATEGORY_##Name()


/**
 * @def NYX_DECLARE_LOG_CATEGORY(Name)
 * @brief Declares a logging category defined elsewhere.
 * 
 * This should be places in a header file to acess a category defined in a .cpp.
 * 
 * @code
 * // In header
 * NYX_DECLARE_LOG_CATEGORY(Renderer);
 * 
 * // In cpp
 * NYX_DEFINE_LOG_CATEGORY(Renderer);
 * @endcode
 */
#define NYX_DECLARE_LOG_CATEGORY(Name) \
    const ::Nyxara::Logging::Category& NYX_GET_LOG_CATEGORY_##Name(); \
    static const ::Nyxara::Logging::Category& Name = NYX_GET_LOG_CATEGORY_##Name()

/**
 * @def NYX_SET_LOG_LEVEL(CAT, LEVEL)
 * @brief Sets the verbosity level for the specified logging category.
 * 
 * @param CAT The logging category.
 * @param LEVEL The desired verbosity level (e.g., Verbosity::Info).
 */
#define NYX_SET_LOG_LEVEL(CAT, LEVEL) \
            ::Nyxara::Logging::Logger::SetCategoryLevel(CAT, LEVEL)

/**
 * @def NYX_LOG(CAT, LEVEL, ...)
 * @brief Logs a message at the specified verbosity level under the given category.
 * 
 * @param CAT the logging category.
 * @param LEVEL Verbosity level (e.g., Verbosity::Warn).
 * @param ... Format string and arguments (fmt-style).
 */
#define NYX_LOG(CAT, LEVEL, ...) \
            ::Nyxara::Logging::Logger::Log(CAT, LEVEL, __VA_ARGS__)


// ----------------------------------------------------------------------------
// Convenience log level macros
// ----------------------------------------------------------------------------

/**
 * @brief Logs a critical error message.
 */
#define NYX_LOG_CRITICAL(CAT, ...) NYX_LOG(CAT, ::Nyxara::Logging::Verbosity::Critical, __VA_ARGS__)

/**
 * @brief Logs an error message.
 */
#define NYX_LOG_ERROR(CAT, ...) NYX_LOG(CAT, ::Nyxara::Logging::Verbosity::Error, __VA_ARGS__)

/**
 * @brief Logs an warning message.
 */
#define NYX_LOG_WARN(CAT, ...)  NYX_LOG(CAT, ::Nyxara::Logging::Verbosity::Warn,  __VA_ARGS__)

/**
 * @brief Logs an informational message.
 */
#define NYX_LOG_INFO(CAT, ...)  NYX_LOG(CAT, ::Nyxara::Logging::Verbosity::Info,  __VA_ARGS__)

/**
 * @brief Logs a debug message.
 */
#define NYX_LOG_DEBUG(CAT, ...) NYX_LOG(CAT, ::Nyxara::Logging::Verbosity::Debug, __VA_ARGS__)

/**
 * @brief Logs a trace message.
 */
#define NYX_LOG_TRACE(CAT, ...) NYX_LOG(CAT, ::Nyxara::Logging::Verbosity::Trace, __VA_ARGS__)

/**
 * @def NYX_TRACE_FUNCTION(CAT)
 * @brief Logs entry and exit of the current function using FunctionTracer.
 * 
 * Useful for tracing function calls automatically.
 * 
 * @param CAT The logging category to log under.
 * 
 * @code
 * void RenderFrame()
 * {
 *      NYX_TRACE_FUNCTION(Renderer);
 *      // Function body...
 * }
 * @endcode
 */
#define NYX_TRACE_FUNCTION(CAT) ::Nyxara::Logging::FunctionTracer tracer(CAT, __func__)

// ----------------------------------------------------------------------------
// Call depth management
// ----------------------------------------------------------------------------

/**
 * @brief Enables call depth-based log indentation globally.
 */
#define NYX_LOG_ENABLE_CALL_DEPTH() ::Nyxara::Logging::Logger::EnableCallDepth()

/**
 * @brief Disables call depth-based log indentation globally.
 */
#define NYX_LOG_DISABLE_CALL_DEPTH() ::Nyxara::Logging::Logger::DisableCallDepth()

/** @} */
