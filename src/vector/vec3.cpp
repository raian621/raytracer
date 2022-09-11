#include "vector/vec3.h"
#include <cmath>

vec3::vec3(float x, float y, float z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

float vec3::magnitude() const
{
  return sqrtf32(this->x * this->x 
    + this->y * this->y + this->z * this->z);
}
vec3 vec3::normalize() const { return *this / magnitude(); }

vec3 vec3::operator+(const vec3& v) const
{
  return {
    this->x + v.x,
    this->y + v.y,
    this->z + v.z
  };
}
vec3 vec3::operator-(const vec3& v) const
{
  return {
    this->x - v.x,
    this->y - v.y,
    this->z - v.z
  };
}
vec3 vec3::operator-() const { return { -x, -y, -z }; }
vec3 vec3::operator*(float n) const
{
  return {
    this->x * n,
    this->y * n,
    this->z * n
  };
}
vec3 vec3::operator*(const mat4& matrix)
{
  return {
    x * (matrix[0][0] + matrix[0][1] + matrix[0][2] + matrix[0][3]),
    y * (matrix[1][0] + matrix[1][1] + matrix[1][2] + matrix[1][3]),
    z * (matrix[2][0] + matrix[2][1] + matrix[2][2] + matrix[2][3])
  };
}
vec3 vec3::operator/(float n) const
{
  return {
    this->x / n,
    this->y / n,
    this->z / n
  };
}

vec3& vec3::operator+=(const vec3& v) { return (*this = *this + v); }
vec3& vec3::operator-=(const vec3& v) { return (*this = *this - v); }
vec3& vec3::operator*=(float n) { return (*this = *this * n); }
vec3& vec3::operator/=(float n) { return (*this = *this / n); }

bool vec3::operator==(const vec3& v) const 
{
  return x == v.x && y == v.y && z == v.z;
}

float dot_product(const vec3& v1, const vec3& v2) noexcept
{
  return { v1.x * v2.x + v1.y * v2.y + v1.z * v2.z };
}
vec3 cross_product(const vec3& v1, const vec3& v2) noexcept
{
  return { 
    v1.y * v2.z - v1.z * v2.y, 
    v1.z * v2.x - v1.x * v2.z,
    v1.x * v2.y - v1.y * v2.x 
  };
}
std::ostream& operator<<(std::ostream& out, const vec3& v)
{
  return (out << '(' << v.x << ", " << v.y << ", " << v.z << ')');
}
vec3 operator*(float n, const vec3& v) { return v * n; }