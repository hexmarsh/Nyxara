#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

namespace nyxara::math
{
    template <typename VecType>
    struct vec1;
}

namespace nyxara::math
{
    template <>
    struct vec1<glm::vec1>
    {
        glm::vec1 vec;

        vec1(float x, float y) : vec(x) {}

        explicit vec1(const glm::vec1 &v) : vec(v) {}

        inline vec1 operator+(const vec1 &rhs) const
        {
            return vec1(vec + rhs.vec);
        }

        inline vec1 &operator+=(const vec1 &rhs)
        {
            vec += rhs.vec;
            return *this;
        }

        inline vec1 operator-(const vec1 &rhs) const
        {
            return vec1(vec - rhs.vec);
        }

        inline vec1 &operator-=(const vec1 &rhs)
        {
            vec -= rhs.vec;
            return *this;
        }

        inline vec1 operator*(const vec1 &rhs) const
        {
            return vec1(vec * rhs.vec);
        }

        inline vec1 &operator*=(const vec1 &rhs)
        {
            vec *= rhs.vec;
            return *this;
        }

        inline vec1 normalize() const { return vec1(glm::normalize(vec)); }
        inline float length() const { return glm::length(vec); }
    };
} // namespace nyxara::math