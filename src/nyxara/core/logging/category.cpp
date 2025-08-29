#include "nyxara/core/logging/category.h"
#include "nyxara/core/logging/logger.h"

namespace nyxara::logging 
{
    Category::Category(const std::string& name)
        : Name(name), Logger(Logger::GetOrCreateLogger(Name))
    {}

    Category::Category(std::string&& name)
        : Name(std::move(name)), Logger(Logger::GetOrCreateLogger(Name))
    {}
} // namespace nyxara::logging