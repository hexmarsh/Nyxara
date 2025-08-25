#pragma once
#include "nyxara/logging/logger.h"
#include "nyxara/logging/verbosity.h"
#include "nyxara/logging/category.h"
#include "nyxara/logging/call_depth.h"

namespace nyxara::logging 
{
    class function_tracer 
    {
    public:
        function_tracer(const category& cat, const char* func)
            : _category(cat), _func(func)
        {
            logger::log(_category, verbosity::trace, "\033[96m=> Entering: {}()\033[0m", _func);
            call_depth_manager::increment();
        }

        ~function_tracer()
        {
            call_depth_manager::decrement();
            logger::log(_category, verbosity::trace, "\033[95m<= Leaving:  {}()\033[0m", _func);
        }

    private:
        const category& _category;
        const char* _func;
    };
} // namespace nyxara::logging

