#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

namespace nyxara::math
{
	// Vector types
	using vec2 = glm::vec2;
	using vec3 = glm::vec3;
	using vec4 = glm::vec4;

	// Matrix types
	using mat3 = glm::mat3;
	using mat4 = glm::mat4;

	// Common functions
	using ::glm::normalize;
	using ::glm::dot;
	using ::glm::cross;
	using ::glm::length;
	using ::glm::distance;
	using ::glm::rotate;
	using ::glm::translate;
	using ::glm::transpose;
	using ::glm::degrees;
	using ::glm::radians;
	using ::glm::to_string;

	constexpr float PI = glm::pi<float>();
} // namespace nyxara::math

