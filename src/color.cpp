#include "color.h"

color::color(float r, float g, float b)
{
  this->r = r;
  this->g = g;
  this->b = b;
}

uint32_t color::int_rgb() const
{
  return ((uint32_t)(r*255) << 16 | (uint32_t)(g*255) << 8 | (uint32_t)(b*255));
}

color color::operator+(const color& c) const
{
  return {
    this->r + c.r,
    this->g + c.g,
    this->b + c.b
  };
}
color color::operator-(const color& c) const
{
  return {
    this->r - c.r,
    this->g - c.g,
    this->b - c.b
  };
}
color color::operator-() const { return { -r, -g, -b }; }
color color::operator*(float n) const
{
  return {
    this->r * n,
    this->g * n,
    this->b * n
  };
}
color color::operator/(float n) const
{
  return {
    this->r / n,
    this->g / n,
    this->b / n
  };
}

color& color::operator+=(const color& c) { return (*this = *this + c); }
color& color::operator-=(const color& c) { return (*this = *this - c); }
color& color::operator*=(float n) { return (*this = *this * n); }
color& color::operator/=(float n) { return (*this = *this / n); }

bool color::operator==(const color& c) const 
{
  return r == c.r && g == c.g && b == c.b;
}

float clamp(float x) noexcept
{ 
  return (x > 1.0f ? 1.0f : x < 0.0f ? 0.0f : x);
}
color clamp(const color& c) noexcept
{
  return { clamp(c.r), clamp(c.g), clamp(c.b) };
}
float dot_product(const color& c1, const color& c2) noexcept
{
  return { c1.r * c2.r + c1.g * c2.g + c1.b * c2.b };
}
color cross_product(const color& c1, const color& c2) noexcept
{
  return { 
    c1.g * c2.b - c1.b * c2.g, 
    c1.b * c2.r - c1.r * c2.b,
    c1.r * c2.g - c1.g * c2.r 
  };
}
std::ostream& operator<<(std::ostream& out, const color& c)
{
  return (out << std::hex << c.int_rgb());
}
color operator*(float n, const color& c) { return c * n; }