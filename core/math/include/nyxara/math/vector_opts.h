#pragma once
#include "nyxara/math/types.h"

namespace nyxara::math
{
	inline vec3 cross(const vec3& a, const vec3& b) { return glm::cross(a, b); }
	inline vec2 normalize(const vec2& v) { return glm::normalize(v); }
	inline vec3 normalize(const vec3& v) { return glm::normalize(v); }
	inline vec4 normalize(const vec4& v) { return glm::normalize(v); }
	inline float dot(const vec2& a, const vec2& b) { return glm::dot(a, b); }
	inline float dot(const vec3& a, const vec3& b) { return glm::dot(a, b); }
	inline float dot(const vec4& a, const vec4& b) { return glm::dot(a, b); }
	inline float length(const vec2& v) { return glm::length(v); }
	inline float length(const vec3& v) { return glm::length(v); }
	inline float length(const vec4& v) { return glm::length(v); }
	inline float distance(const vec2& a, const vec2& b) { return glm::distance(a, b); }
	inline float distance(const vec3& a, const vec3& b) { return glm::distance(a, b); }
	inline float distance(const vec4& a, const vec4& b) { return glm::distance(a, b); }
} // namespace nyxara::math

