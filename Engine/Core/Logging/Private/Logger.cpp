#include "Engine/Core/Logging/Logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Nyxara::Logging
{
    std::once_flag InitFlag;

    void Logger::Init()
    {
        std::call_once(InitFlag, []() {
            spdlog::set_level(spdlog::level::info);
            spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^%L%$] [thread %t] %v");
            });
    }

    void Logger::SetCategoryLevel(const Category& category, Verbosity level)
    {
        std::unique_lock lock(LevelsMutex);
        CategoryLevels[category.GetName()] = level;
        
        std::shared_ptr<spdlog::logger> loggerPtr = category.GetLogger();

        if (loggerPtr)
        {
            loggerPtr->set_level(to_spdlog_level(level));
        }
    }

    std::shared_ptr<spdlog::logger> Logger::GetOrCreateLogger(const std::string& name)
    {
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
        std::shared_lock lock(LevelsMutex);
        auto it = CategoryLevels.find(cat_name);
        if (it != CategoryLevels.end())
        {
            return it->second;
        }

        return Verbosity::Info; // default log level
    }
} // namespace nyx::logging