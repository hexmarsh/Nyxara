#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

namespace nyxara::math
{
    template <typename VecType>
    struct vec4;
}

namespace nyxara::math
{
    template <>
    struct vec4<glm::vec4>
    {
        glm::vec4 vec;

        vec4(float x, float y, float z, float w) : vec(x, y, z, w) {}

        explicit vec4(const glm::vec4 &v) : vec(v) {}

        inline vec4 operator+(const vec4 &rhs) const
        {
            return vec4(vec + rhs.vec);
        }

        inline vec4 &operator+=(const vec4 &rhs)
        {
            vec += rhs.vec;
            return *this;
        }

        inline vec4 operator-(const vec4 &rhs) const
        {
            return vec4(vec - rhs.vec);
        }

        inline vec4 &operator-=(const vec4 &rhs)
        {
            vec -= rhs.vec;
            return *this;
        }

        inline vec4 operator*(const vec4 &rhs) const
        {
            return vec4(vec * rhs.vec);
        }

        inline vec4 &operator*=(const vec4 &rhs)
        {
            vec *= rhs.vec;
            return *this;
        }

        inline vec4 normalize() const { return vec4(glm::normalize(vec)); }
        inline float length() const { return glm::length(vec); }
    };
} // namespace nyxara::math