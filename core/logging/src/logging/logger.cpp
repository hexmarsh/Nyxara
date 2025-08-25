#include "nyxara/logging/logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace nyxara::logging
{
    std::once_flag _init_flag;

    void logger::init()
    {
        std::call_once(_init_flag, []() {
            spdlog::set_level(spdlog::level::info);
            spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^%L%$] [thread %t] %v");
            });
    }

    void logger::set_category_level(const category& cat, verbosity level)
    {
        std::unique_lock lock(_levels_mutex);
        _category_levels[cat.get_name()] = level;
        
        auto logger_ptr = cat.get_logger();

        if (logger_ptr)
        {
            logger_ptr->set_level(to_spdlog_level(level));
        }
    }

    std::shared_ptr<spdlog::logger> logger::get_or_create_logger(const std::string& name)
    {
        std::shared_ptr<spdlog::logger> existing_logger = spdlog::get(name);

        if (existing_logger)
        {
            return existing_logger;
        }

        std::shared_ptr<spdlog::logger> new_logger = spdlog::stdout_color_mt(name);

        return new_logger;
    }

    verbosity logger::get_category_level(const std::string& cat_name)
    {
        std::shared_lock lock(_levels_mutex);
        auto it = _category_levels.find(cat_name);
        if (it != _category_levels.end())
        {
            return it->second;
        }

        return verbosity::info; // default log level
    }
} // namespace nyxara::logging