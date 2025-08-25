#pragma once

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace nyxara::math
{
	// Vector types
	using vec2 = glm::vec2;
	using vec3 = glm::vec3;
	using vec4 = glm::vec4;

	// Matrix types
	using mat3 = glm::mat3;
	using mat4 = glm::mat4;

	inline constexpr float degrees(float radians) { return glm::degrees(radians); }
	inline constexpr float radians(float degrees) { return glm::radians(degrees); }

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

	template <typename MatrixType, typename VectorType>
	auto rotate(const MatrixType& m, float angle, const VectorType& axis)
	{
		return glm::rotate(m, angle, axis);
	}

	template <typename MatrixType, typename VectorType>
	auto translate(const MatrixType& m, const VectorType& translation)
	{
		return glm::translate(m, translation);
	}

	template <typename MatrixType, typename VectorType>
	auto scale(const MatrixType& m, const VectorType& scale)
	{
		return glm::scale(m, scale);
	}

	inline auto perspective(float fovRadians, float aspect, float near, float far)
	{
		return glm::perspective(fovRadians, aspect, near, far);
	}

	inline auto ortho(float left, float right, float bottom, float top, float near = -1.0f, float far = 1.0f)
	{
		return glm::ortho(left, right, bottom, top, near, far);
	}

	template <typename VectorType>
	auto lookAt(const VectorType& eye, const VectorType& center, const VectorType& up)
	{
		return glm::lookAt(eye, center, up);
	}
}