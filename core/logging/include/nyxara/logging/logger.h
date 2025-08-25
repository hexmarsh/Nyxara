#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/fmt/fmt.h>
#include <shared_mutex>
#include <unordered_map>
#include <string>
#include <string_view>
#include <mutex>
#include <memory>

namespace nyxara::logging
{
    enum class verbosity
    {
        none = 0,
        fatal,
        error,
        warn,
        info,
        debug,
        trace
    };

    constexpr spdlog::level::level_enum to_spdlog_level(verbosity level) noexcept
    {
        switch (level)
        {
        case verbosity::fatal: return spdlog::level::critical;
        case verbosity::error: return spdlog::level::err;
        case verbosity::warn:  return spdlog::level::warn;
        case verbosity::info:  return spdlog::level::info;
        case verbosity::debug: return spdlog::level::debug;
        case verbosity::trace: return spdlog::level::trace;
        default:               return spdlog::level::off;
        }
    }

    // Forward declarations
    class logger;
    class category;

    class category
    {
    public:
        explicit category(std::string name);
        
        const std::string& get_name() const noexcept { return _name; }
        std::shared_ptr<spdlog::logger> get_logger() const noexcept { return _logger; }

    private:
        std::string _name;
        std::shared_ptr<spdlog::logger> _logger;
    };

    class logger
    {
    public:
        static void init();
        static void set_category_level(const category& cat, verbosity level);

        template<typename... Args>
        static void log(const category& cat, verbosity level, fmt::format_string<Args...> fmt_str, Args&&... args)
        {
            if (level == verbosity::none) 
            {
                return;
            }

            verbosity cat_level = get_category_level(cat.get_name());

            if (level > cat_level)
            {
                return;
            }

            auto logger_ptr = cat.get_logger();
            if (logger_ptr->should_log(to_spdlog_level(level)))
            {
                logger_ptr->log(to_spdlog_level(level), fmt_str, std::forward<Args>(args)...);
            }
        }

        static std::shared_ptr<spdlog::logger> get_or_create_logger(const std::string& name);

    private:
        friend class category;

        static verbosity get_category_level(const std::string& cat_name);

        inline static std::unordered_map<std::string, std::shared_ptr<spdlog::logger>> _loggers;
        inline static std::unordered_map<std::string, verbosity> _category_levels;
        inline static std::shared_mutex _loggers_mutex;
        inline static std::shared_mutex _levels_mutex;

        inline static bool _initialized = false;
        inline static std::mutex _init_mutex;
    };
} // namespace nyxara::logging

