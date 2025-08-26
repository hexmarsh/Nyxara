#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

namespace nyxara::math
{
    template <typename VecType>
    struct vec3;
}

namespace nyxara::math
{
    template <>
    struct vec3<glm::vec3>
    {
        glm::vec3 vec;

        vec3(float x, float y, float z) : vec(x, y, z) {}

        explicit vec3(const glm::vec3 &v) : vec(v) {}

        inline vec3 operator+(const vec3 &rhs) const
        {
            return vec3(vec + rhs.vec);
        }

        inline vec3 &operator+=(const vec3 &rhs)
        {
            vec += rhs.vec;
            return *this;
        }

        inline vec3 operator-(const vec3 &rhs) const
        {
            return vec3(vec - rhs.vec);
        }

        inline vec3 &operator-=(const vec3 &rhs)
        {
            vec -= rhs.vec;
            return *this;
        }

        inline vec3 operator*(const vec3 &rhs) const
        {
            return vec3(vec * rhs.vec);
        }

        inline vec3 &operator*=(const vec3 &rhs)
        {
            vec *= rhs.vec;
            return *this;
        }

        inline vec3 normalize() const { return vec3(glm::normalize(vec)); }
        inline float length() const { return glm::length(vec); }
    };
} // namespace nyxara::math