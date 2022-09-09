#include "vector/vec2.h"

#include <cmath>

float x, y;

vec2::vec2(float x, float y)
{
  this->x = x;
  this->y = y;
}

float vec2::magnitude() const 
{ 
  return sqrtf32(this->x * this->x + this->y * this->y);
}
vec2 vec2::normalize() const { return *this / magnitude(); }

vec2 vec2::operator+(const vec2& v) const { return { this->x + v.x, this->y + v.y }; }
vec2 vec2::operator-(const vec2& v) const { return *this + -v; }
vec2 vec2::operator-() const { return { -this->x, -this->y }; }
vec2 vec2::operator*(float n) const { return { this->x * n, this->y * n }; }
vec2 vec2::operator/(float n) const { return { this->x / n, this->y / n }; }

vec2& vec2::operator+=(const vec2& v) { return (*this = *this + v); }
vec2& vec2::operator-=(const vec2& v) { return (*this = *this - v); }
vec2& vec2::operator*=(float n) { return (*this = *this * n); }
vec2& vec2::operator/=(float n) { return (*this = *this / n); }

bool vec2::operator==(const vec2& v) const 
{
  return (this->x == v.x && this->y == v.y);
};

float dot_product(const vec2& v1, const vec2& v2) noexcept
{
  return (v1.x * v2.x + v1.y + v2.y);
}
std::ostream& operator<<(std::ostream& out, const vec2& v)
{
  return (out << '(' << v.x << ", " << v.y << ')');
}
vec2 operator*(float n, const vec2& v)
{
  return v * n;
}
