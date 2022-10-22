#include "color.h"

color::color(float r, float g, float b, float a)
  : vec4::vec4(r, g, b, a)
{}

uint32_t color::int_rgb() const
{
  return ((uint32_t)(r*255) << 16 | (uint32_t)(g*255) << 8 | (uint32_t)(b*255));
}

float clamp(float x) noexcept
{ 
  return (x > 1.0f ? 1.0f : x < 0.0f ? 0.0f : x);
}
color clamp(const color& c) noexcept
{
  return { clamp(c.r), clamp(c.g), clamp(c.b) };
}
std::ostream& operator<<(std::ostream& out, const color& c)
{
  return (out << std::hex << c.int_rgb());
}