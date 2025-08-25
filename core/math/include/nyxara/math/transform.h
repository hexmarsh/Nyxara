#pragma once
#include "nyxara/math/types.h"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace nyxara::math
{
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
} // namespace nyxara::math
