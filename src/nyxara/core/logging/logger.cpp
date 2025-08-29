#include <spdlog/sinks/stdout_color_sinks.h>
#include "nyxara/core/logging/logger.h"

namespace nyxara::logging
{
    class LoggerImpl
    {
    public:
        static LoggerImpl& GetInstance()
        {
            static LoggerImpl instance;
            return instance;
        }

        std::unordered_map<std::string, Verbosity> CategoryLevels;
        std::shared_mutex LevelsMutex;

    private:
        LoggerImpl()
        {
            // Initialize spdlog during first access
            spdlog::set_level(spdlog::level::info);
            spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^%L%$] %v");
        }
    };

    void Logger::Init()
    {
        // Force initialization of the singleton
        LoggerImpl::GetInstance();
    }

    void Logger::SetCategoryLevel(const Category& category, Verbosity level)
    {
        auto& impl = LoggerImpl::GetInstance();

        std::unique_lock lock(impl.LevelsMutex);
        impl.CategoryLevels[category.GetName()] = level;
        
        std::shared_ptr<spdlog::logger> loggerPtr = category.GetLogger();

        if (loggerPtr)
        {
            loggerPtr->set_level(to_spdlog_level(level));
        }
    }

    std::shared_ptr<spdlog::logger> Logger::GetOrCreateLogger(const std::string& name)
    {
        auto& impl = LoggerImpl::GetInstance();

        std::shared_ptr<spdlog::logger> existingLogger = spdlog::get(name);

        if (existingLogger)
        {
            return existingLogger;
        }

        std::shared_ptr<spdlog::logger> new_logger = spdlog::stdout_color_mt(name);

        return new_logger;
    }

    Verbosity Logger::GetCategoryLevel(const std::string& cat_name)
    {
        auto& impl = LoggerImpl::GetInstance();
        
        std::shared_lock lock(impl.LevelsMutex);
        auto it = impl.CategoryLevels.find(cat_name);
        if (it != impl.CategoryLevels.end())
        {
            return it->second;
        }

        return Verbosity::Info; // default log level
    }
} // namespace nyxara::logging