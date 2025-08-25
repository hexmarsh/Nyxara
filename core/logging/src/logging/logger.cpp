#include "nyxara/logging/logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace nyxara::logging
{
    void logger::init()
    {
        std::scoped_lock lock(_init_mutex);
        if (_initialized) return;

        // Set global default level
        spdlog::set_level(spdlog::level::info);

        _initialized = true;
    }

    void logger::set_category_level(const category& cat, verbosity level)
    {
        std::unique_lock lock(_levels_mutex);
        _category_levels[cat.get_name()] = level;
        
        // Also update the spdlog logger's level
        auto logger_ptr = cat.get_logger();
        if (logger_ptr)
        {
            logger_ptr->set_level(to_spdlog_level(level));
        }
    }

    std::shared_ptr<spdlog::logger> logger::get_or_create_logger(const std::string& name)
    {
        {
            std::shared_lock read_lock(_loggers_mutex);
            auto it = _loggers.find(name);
            if (it != _loggers.end())
            {
                return it->second; // logger already exists - fast path
            }
        }

        // Upgrade to unique lock if logger not found
        std::unique_lock write_lock(_loggers_mutex);

        // Double check after acquiring write lock
        auto it = _loggers.find(name);
        if (it != _loggers.end())
        {
            return it->second;
        }

        auto new_logger = spdlog::stdout_color_mt(name);
        
        // Set the pattern for this specific logger
        spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^%L%$] [thread %t] %v");

        // Set default level for new loggers
        new_logger->set_level(to_spdlog_level(verbosity::info));
        
        _loggers[name] = new_logger;
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