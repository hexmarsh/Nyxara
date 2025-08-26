#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

namespace nyxara::math
{
  template <typename VecType>
  struct vec2;
}

namespace nyxara::math
{
  template <>
  struct vec2<glm::vec2>
  {
    glm::vec2 vec;

    vec2(float x, float y) : vec(x, y) {}

    explicit vec2(const glm::vec2 &v) : vec(v) {}

    inline vec2 operator+(const vec2 &rhs) const
    {
      return vec2(vec + rhs.vec);
    }

    inline vec2 &operator+=(const vec2 &rhs)
    {
      vec += rhs.vec;
      return *this;
    }

    inline vec2 operator-(const vec2 &rhs) const
    {
      return vec2(vec - rhs.vec);
    }

    inline vec2 &operator-=(const vec2 &rhs)
    {
      vec -= rhs.vec;
      return *this;
    }

    inline vec2 operator*(const vec2 &rhs) const
    {
      return vec2(vec * rhs.vec);
    }

    inline vec2 &operator*=(const vec2 &rhs)
    {
      vec *= rhs.vec;
      return *this;
    }

    inline vec2 normalize() const { return vec2(glm::normalize(vec)); }
    inline float length() const { return glm::length(vec); }
  };
} // namespace nyxara::math