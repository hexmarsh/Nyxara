#pragma once
#include <memory>
#include <shared_mutex>
#include <spdlog/fmt/fmt.h>
#include <string>
#include <unordered_map>

#include "nyxara/logging/category.h"
#include "nyxara/logging/verbosity.h"

// forward declarations
namespace spdlog { class logger; }

namespace nyxara::logging 
{
    class logger 
    {
    public:
        static void init();
        static void set_category_level(const category& cat, verbosity level);

        template<typename... Args>
        static void log(const category& cat, verbosity level, fmt::format_string<Args...> fmt_str, Args&&... args) {
            if (level == verbosity::none) return;

            verbosity cat_level = get_category_level(cat.get_name());
            if (level > cat_level) return;

            auto logger_ptr = cat.get_logger();
            if (logger_ptr->should_log(to_spdlog_level(level))) {
                logger_ptr->log(to_spdlog_level(level), fmt_str, std::forward<Args>(args)...);
            }
        }

        static std::shared_ptr<spdlog::logger> get_or_create_logger(const std::string& name);

    private:
        static verbosity get_category_level(const std::string& cat_name);

        inline static std::unordered_map<std::string, std::shared_ptr<spdlog::logger>> _loggers;
        inline static std::unordered_map<std::string, verbosity> _category_levels;
        inline static std::shared_mutex _loggers_mutex;
        inline static std::shared_mutex _levels_mutex;
        inline static bool _initialized = false;
        inline static std::mutex _init_mutex;
    };
} // namespace nyxara::logging

