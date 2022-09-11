#include "vector/vec4.h"
#include <cmath>

vec4::vec4(float x, float y, float z, float w)
{
  this->x = x;
  this->y = y;
  this->z = z;
  this->w = w;
}

float vec4::magnitude() const
{
  return sqrtf32(this->x * this->x +
                 this->y * this->y + 
                 this->z * this->z +
                 this->w * this->w);
}
vec4 vec4::normalize() const { return *this / magnitude(); }

vec4 vec4::operator+(const vec4& v) const
{
  return {
    this->x + v.x,
    this->y + v.y,
    this->z + v.z,
    this->w + v.w
  };
}
vec4 vec4::operator-(const vec4& v) const
{
  return {
    this->x - v.x,
    this->y - v.y,
    this->z - v.z,
    this->w - v.w
  };
}
vec4 vec4::operator-() const { return { -x, -y, -z, -w }; }
vec4 vec4::operator*(float n) const
{
  return {
    this->x * n,
    this->y * n,
    this->z * n,
    this->w * n
  };
}
vec4 vec4::operator*(const mat4& matrix) const
{
  return {
    x * (matrix[0][0] + matrix[0][1] + matrix[0][2] + matrix[0][3]),
    y * (matrix[1][0] + matrix[1][1] + matrix[1][2] + matrix[1][3]),
    z * (matrix[2][0] + matrix[2][1] + matrix[2][2] + matrix[2][3]),
    w * (matrix[3][0] + matrix[3][1] + matrix[3][2] + matrix[3][3]),
  };
}
vec4 vec4::operator/(float n) const
{
  return {
    this->x / n,
    this->y / n,
    this->z / n,
    this->w / n
  };
}

vec4& vec4::operator+=(const vec4& v) { return (*this = *this + v); }
vec4& vec4::operator-=(const vec4& v) { return (*this = *this - v); }
vec4& vec4::operator*=(float n) { return (*this = *this * n); }
vec4& vec4::operator/=(float n) { return (*this = *this / n); }

bool vec4::operator==(const vec4& v) const 
{
  return x == v.x && y == v.y && z == v.z && w == v.w;
}

float dot_product(const vec4& v1, const vec4& v2) noexcept
{
  return { v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w };
}
vec3 cross_product(const vec4& v1, const vec4& v2) noexcept
{
  return { 
    v1.y * v2.z - v1.z * v2.y, 
    v1.z * v2.x - v1.x * v2.z,
    v1.x * v2.y - v1.y * v2.x
  };
}
std::ostream& operator<<(std::ostream& out, const vec4& v)
{
  return (out << '(' << v.x << ", " << v.y << ", " << v.z << ')');
}
vec4 operator*(float n, const vec4& v) { return v * n; }