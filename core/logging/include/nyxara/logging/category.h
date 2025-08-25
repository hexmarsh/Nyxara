#pragma once
#include <memory>
#include <string>

// forward declarations
namespace spdlog { class logger; }
namespace nyxara::logging { class logger; }

namespace nyxara::logging 
{

    class category 
    {
    public:
        explicit category(std::string name);

        inline const std::string& get_name() const noexcept { return _name; }
        inline std::shared_ptr<spdlog::logger> get_logger() const noexcept { return _logger; }

    private:
        std::string _name;
        std::shared_ptr<spdlog::logger> _logger;
    };
} // namespace nyxara::logging

