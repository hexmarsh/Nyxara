#pragma once
#include "nyxara/math/types.h"

namespace nyxara::math
{
	inline constexpr float degrees(float radians) { return glm::degrees(radians); }
	inline constexpr float radians(float degrees) { return glm::radians(degrees); }
} // namespace nyxara::math