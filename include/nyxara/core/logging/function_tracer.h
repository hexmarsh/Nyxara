#pragma once

#include "nyxara/core/logging/call_depth_manager.h"
#include "nyxara/core/logging/category.h"
#include "nyxara/core/logging/logger.h"
#include "nyxara/core/logging/verbosity.h"

namespace Nyxara::Logging 
{
    /**
     * @brief RAII helper class to trace function entry and exit.
     * 
     * Logs entering and leaving messages at Verbosity::Trace level, using
     * call depth to add depth information to nested calls for better readability.
     * 
     * Typically instantiated at the start of a function scope to automatically
     * log an entry and exit.
     */
    class FunctionTracer 
    {
    public:
        /**
         * @brief Constructs a FunctionTracer and logs the function entry.
         * 
         * @param category The logging category to use.
         * @param functionName The name of the function being traced.
         */
        FunctionTracer(const Category& category, const char* functionName)
            : Category(category), FunctionName(functionName)
        {
            Logger::Log(Category, Verbosity::Trace, "\033[96m=> Entering: {}()\033[0m", FunctionName);
            CallDepthManager::Increment();
        }

        /**
         * @brief Destructor that logs the function exit and decreases call depth.
         */
        ~FunctionTracer()
        {
            CallDepthManager::Decrement();
            Logger::Log(Category, Verbosity::Trace, "\033[95m<= Leaving:  {}()\033[0m", FunctionName);
        }

    private:
        const Category& Category;   ///< Logging category used for messages.
        const char* FunctionName;   ///< Name of the function being traced.
    };
} // namespace Nyxara::Logging

