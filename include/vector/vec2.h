#ifndef VEC2_H
#define VEC2_H

#include <iostream>

struct vec2
{
  union
  {
    struct { float x, y; };
    struct { float s, t; };
  };

  vec2(float x = 0, float y = 0);

  float magnitude() const;
  vec2 normalize() const;

  vec2 operator+(const vec2&) const;
  vec2 operator-(const vec2&) const;
  vec2 operator-() const;
  vec2 operator*(float) const;
  vec2 operator/(float) const;

  vec2& operator+=(const vec2&);
  vec2& operator-=(const vec2&);
  vec2& operator*=(float);
  vec2& operator/=(float);

  bool operator==(const vec2&) const;
};

float dot(const vec2&, const vec2&) noexcept;
std::ostream& operator<<(std::ostream&, const vec2&);
vec2 operator*(float, const vec2&);

#endif