#ifndef VEC4_H
#define VEC4_H

#include <iostream>
#include "vec3.h"
struct vec4
{
  float x, y, z, w;

  vec4(float x = 0, float y = 0, float z = 0, float w = 0);

  float magnitude() const;
  vec4 normalize() const;

  vec4 operator+(const vec4&) const;
  vec4 operator-(const vec4&) const;
  vec4 operator-() const;
  vec4 operator*(float) const;
  vec4 operator*(const mat4&) const;
  vec4 operator/(float) const;

  vec4& operator+=(const vec4&);
  vec4& operator-=(const vec4&);
  vec4& operator*=(float);
  vec4& operator/=(float);

  bool operator==(const vec4&) const;
};

float dot_product(const vec4&, const vec4&) noexcept;
vec3 cross_product(const vec4&, const vec4&) noexcept;
std::ostream& operator<<(std::ostream&, const vec4&);
vec4 operator*(float, const vec4&);

#endif