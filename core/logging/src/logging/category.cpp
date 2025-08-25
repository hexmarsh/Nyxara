#include "nyxara/logging/category.h"
#include "nyxara/logging/logger.h"

namespace nyxara::logging 
{
    category::category(std::string name)
        : _name(std::move(name))
    {
        // Cache logger pointer on construction to avoid repeated lookups
        _logger = logger::get_or_create_logger(_name);
    }
} // namespace nyxara::logging