#pragma once
#include "nyxara/logging/logger.h"
#include "nyxara/logging/verbosity.h"
#include "nyxara/logging/category.h"

namespace nyxara::logging 
{
    class function_tracer 
    {
    public:
        function_tracer(const category& cat, const char* func)
            : _category(cat), _func(func)
        {
            logger::log(_category, verbosity::trace, "{}=> Entering: {}()",
                std::string(_call_depth * 2, ' '), _func);

            ++_call_depth;
        }

        ~function_tracer()
        {
            --_call_depth;

            logger::log(_category, verbosity::trace, "{}<= Leaving:  {}()",
                std::string(_call_depth * 2, ' '), _func);
        }

    private:
        const category& _category;
        const char* _func;
        static thread_local int _call_depth;
    };

    inline thread_local int function_tracer::_call_depth = 0;
} // namespace nyxara::logging

