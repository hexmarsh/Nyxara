#pragma once

#include "nyxara/core/logging/function_tracer.h"
#include "nyxara/core/logging/logger.h"

/**
 * @defgroup LoggingMacros Nyxara Logging Macros 
 * @brief Useful macros for structured logging and function tracing.
 * @{
 */

/**
 * @def NYX_DECLARE_LOG_CATEGORY(Name)
 * @brief Declares a logging category defined elsewhere.
 * 
 * This macro should be used in header files to declare a logging category
 * that is defined in a source file using NYX_DEFINE_LOG_CATEGORY.
 * 
 * @code
 * NYX_DECLARE_LOG_CATEGORY(Renderer);
 * @endcode
 */
#define NYX_DECLARE_LOG_CATEGORY(Name) \
    extern const ::nyxara::logging::Category Name

/**
 * @def NYX_DEFINE_LOG_CATEGORY(Name)
 * @brief Defines a logging category with the given name.
 * 
 * This macro creates a const instance of a logging category that can be used
 * throughout the application. The category is initialized once per translation unit.
 * 
 * @code
 * NYX_DEFINE_LOG_CATEGORY(Renderer)
 * @endcode
 */
#define NYX_DEFINE_LOG_CATEGORY(Name) \
    const ::nyxara::logging::Category Name(#Name)

/**
 * @def NYX_SET_LOG_LEVEL(CAT, LEVEL)
 * @brief Sets the verbosity level for the specified logging category.
 * 
 * @param CAT The logging category.
 * @param LEVEL The desired verbosity level (e.g., Verbosity::Info).
 */
#define NYX_SET_LOG_LEVEL(CAT, LEVEL) \
            ::nyxara::logging::Logger::SetCategoryLevel(CAT, LEVEL)

/**
 * @def NYX_LOG(CAT, LEVEL, ...)
 * @brief Logs a message at the specified verbosity level under the given category.
 * 
 * @param CAT The logging category.
 * @param LEVEL Verbosity level (e.g., Verbosity::Warn).
 * @param ... Format string and arguments (fmt-style).
 */
#define NYX_LOG(CAT, LEVEL, ...) \
            ::nyxara::logging::Logger::Log(CAT, LEVEL, __VA_ARGS__)


// ----------------------------------------------------------------------------
// Convenience log level macros
// ----------------------------------------------------------------------------

/**
 * @brief Logs a critical error message.
 */
#define NYX_LOG_CRITICAL(CAT, ...) NYX_LOG(CAT, ::nyxara::logging::Verbosity::Critical, __VA_ARGS__)

/**
 * @brief Logs an error message.
 */
#define NYX_LOG_ERROR(CAT, ...) NYX_LOG(CAT, ::nyxara::logging::Verbosity::Error, __VA_ARGS__)

/**
 * @brief Logs a warning message.
 */
#define NYX_LOG_WARN(CAT, ...)  NYX_LOG(CAT, ::nyxara::logging::Verbosity::Warn,  __VA_ARGS__)

/**
 * @brief Logs an informational message.
 */
#define NYX_LOG_INFO(CAT, ...)  NYX_LOG(CAT, ::nyxara::logging::Verbosity::Info,  __VA_ARGS__)

/**
 * @brief Logs a debug message.
 */
#define NYX_LOG_DEBUG(CAT, ...) NYX_LOG(CAT, ::nyxara::logging::Verbosity::Debug, __VA_ARGS__)

/**
 * @brief Logs a trace message.
 */
#define NYX_LOG_TRACE(CAT, ...) NYX_LOG(CAT, ::nyxara::logging::Verbosity::Trace, __VA_ARGS__)

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
#if defined(__GNUC__) || defined(__clang__)
#define NYX_FUNCTION_NAME __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
#define NYX_FUNCTION_NAME __FUNCSIG__
#else
#define NYX_FUNCTION_NAME __func__
#endif

#define NYX_TRACE_FUNCTION(CAT) ::nyxara::logging::FunctionTracer tracer(CAT, NYX_FUNCTION_NAME)


// ----------------------------------------------------------------------------
// Call depth management
// ----------------------------------------------------------------------------

/**
 * @brief Enables call depth-based log information globally.
 */
#define NYX_LOG_ENABLE_CALL_DEPTH() ::nyxara::logging::Logger::EnableCallDepth()

/**
 * @brief Disables call depth-based log information globally.
 */
#define NYX_LOG_DISABLE_CALL_DEPTH() ::nyxara::logging::Logger::DisableCallDepth()

/** @} */
