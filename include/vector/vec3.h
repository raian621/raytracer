#ifndef VEC3_H
#define VEC3_H

#include <iostream>
struct vec3
{
  float x, y, z;

  vec3(float x = 0, float y = 0, float z = 0);

  float magnitude() const;
  vec3 normalize() const;

  vec3 operator+(const vec3&) const;
  vec3 operator-(const vec3&) const;
  vec3 operator-() const;
  vec3 operator*(float) const;
  vec3 operator/(float) const;

  vec3& operator+=(const vec3&);
  vec3& operator-=(const vec3&);
  vec3& operator*=(float);
  vec3& operator/=(float);

  bool operator==(const vec3&) const;
};

float dot(const vec3&, const vec3&) noexcept;
vec3 cross(const vec3&, const vec3&) noexcept;
std::ostream& operator<<(std::ostream&, const vec3&);
vec3 operator*(float, const vec3&);

#endif