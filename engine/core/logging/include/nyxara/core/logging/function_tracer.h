#pragma once

#include "nyxara/core/logging/call_depth_manager.h"
#include "nyxara/core/logging/category.h"
#include "nyxara/core/logging/logger.h"
#include "nyxara/core/logging/verbosity.h"

namespace Nyxara::Logging 
{
    class FunctionTracer 
    {
    public:
        FunctionTracer(const Category& category, const char* functionName)
            : Category(category), FunctionName(functionName)
        {
            Logger::Log(Category, Verbosity::Trace, "\033[96m=> Entering: {}()\033[0m", FunctionName);
            CallDepthManager::Increment();
        }

        ~FunctionTracer()
        {
            CallDepthManager::Decrement();
            Logger::Log(Category, Verbosity::Trace, "\033[95m<= Leaving:  {}()\033[0m", FunctionName);
        }

    private:
        const Category& Category;
        const char* FunctionName;
    };
} // namespace nyx::logging

