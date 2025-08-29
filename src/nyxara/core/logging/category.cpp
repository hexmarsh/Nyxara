#include "nyxara/core/logging/category.h"
#include "nyxara/core/logging/logger.h"

namespace Nyxara::Logging 
{
    Category::Category(std::string name)
        : Name(std::move(name))
    {
        // Cache logger pointer on construction to avoid repeated lookups
        Logger = Logger::GetOrCreateLogger(Name);
    }
} // namespace Nyxara::Logging