#pragma once

#include <memory>
#include <string>

// forward declarations
namespace spdlog { class logger; }
namespace Nyxara::Logging { class Logger; }

namespace Nyxara::Logging 
{

    class Category 
    {
    public:
        explicit Category(std::string name);

        inline const std::string& GetName() const noexcept { return Name; }
        inline std::shared_ptr<spdlog::logger> GetLogger() const noexcept { return Logger; }

    private:
        std::string Name;
        std::shared_ptr<spdlog::logger> Logger;
    };
} // namespace nyx::logging

