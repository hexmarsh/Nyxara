#pragma once

#include <memory>
#include <string>

// forward declarations
namespace spdlog { class logger; }
namespace Nyxara::Logging { class Logger; }

namespace Nyxara::Logging 
{
    /**
     * @brief Represents a named logging category within the Nyxara engine.
     * 
     * Categories allow grouping logs by subsystem or feature area (e.g., "Renderer, "Physics").
     * Each category owns it own logger instance, which can be configured independently.
     * 
     * Used in conjunction with Nyxara::Logging::Logger for structured, per-category logging.
     */
    class Category 
    {
    public:
        /**
         * @brief Constructs a new loggig category with the given name.
         * 
         * @param name The unique name of the logging category.
         */
        explicit Category(std::string name);

        /**
         * @brief Gets the name of the logging category.
         * 
         * @return The category name.
         */
        inline const std::string& GetName() const noexcept { return Name; }

        /**
         * @brief Gets the spdlog logger associated with this category.
         * 
         * @return A shared pointer to the logger.
         */
        inline std::shared_ptr<spdlog::logger> GetLogger() const noexcept { return Logger; }

    private:
        std::string Name;                       ///< Name of the logging category.
        std::shared_ptr<spdlog::logger> Logger; ///< Logger instance associated with this category.
    };
} // namespace nyx::logging

