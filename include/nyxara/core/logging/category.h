#pragma once

#include <memory>
#include <string>

// forward declarations
namespace spdlog { class logger; }
namespace nyxara::logging { class Logger; }

namespace nyxara::logging
{
    /**
     * @brief Represents a named logging category within the Nyxara engine.
     * 
     * Categories allow grouping logs by subsystem or feature area (e.g., "Renderer", "Physics").
     * Each category owns its own logger instance, which can be configured independently.
     * 
     * Used in conjunction with Nyxara::Logging::Logger for structured, per-category logging.
     */
    class Category 
    {
    public:
        /**
         * @brief Constructs a new logging category with the given name.
         *
         * This constructor initializes the category by copying the provided name,
         * then caches the associated logger pointer to avoid repeated lookups.
         *
         * @param name The unique name of the logging category.
         */
        explicit Category(const std::string& name);

        /**
         * @brief Constructs a new logging category by moving the given name.
         *
         * This constructor initializes the category by moving the provided name,
         * then caches the associated logger pointer to avoid repeated lookups.
         *
         * @param name The unique name of the logging category (moved).
         */
        explicit Category(std::string&& name);

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
} // namespace nyxara::logging

