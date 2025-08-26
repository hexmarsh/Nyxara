#include "Engine/Core/Logging/Category.h"
#include "Engine/Core/Logging/Logger.h"

namespace Nyxara::Logging 
{
    Category::Category(std::string name)
        : Name(std::move(name))
    {
        // Cache logger pointer on construction to avoid repeated lookups
        Logger = Logger::GetOrCreateLogger(Name);
    }
} // namespace nyx::logging