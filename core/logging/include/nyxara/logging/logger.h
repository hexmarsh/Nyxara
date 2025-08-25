#pragma once
#include <memory>
#include <shared_mutex>
#include <string>
#include <unordered_map>

#include "nyxara/logging/category.h"
#include "nyxara/logging/verbosity.h"
#include "nyxara/logging/call_depth.h"

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

            if (logger_ptr->should_log(to_spdlog_level(level)))
            {
                if (!call_depth_manager::is_enabled())
                {
                    logger_ptr->log(to_spdlog_level(level), fmt_str, std::forward<Args>(args)...);
                    return;
                }

                // Avoid all allocations by formatting spaces and message directly into buffer
                fmt::memory_buffer buffer;
                auto appender = fmt::appender(buffer);
                fmt::format_to(appender, "{:{}}", "", call_depth_manager::get_indentation_count());
                fmt::format_to(appender, fmt_str, std::forward<Args>(args)...);

                logger_ptr->log(to_spdlog_level(level), fmt::string_view(buffer.data(), buffer.size()));
            }
        }

        static std::shared_ptr<spdlog::logger> get_or_create_logger(const std::string& name);

        // Call depth management for normal logging
        static void enable_call_depth(bool enabled = true) { call_depth_manager::set_enabled(enabled); }
        static bool is_call_depth_enabled() { return call_depth_manager::is_enabled(); }

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

