#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <stdint.h>

struct color
{
  float r, g, b;

  color(float r = 0, float g = 0, float b = 0);

  uint32_t int_rgb() const;

  color operator+(const color&) const;
  color operator-(const color&) const;
  color operator-() const;
  color operator*(float) const;
  color operator/(float) const;

  color& operator+=(const color&);
  color& operator-=(const color&);
  color& operator*=(float);
  color& operator/=(float);

  bool operator==(const color&) const;
};

color clamp(const color&) noexcept;
float dot_product(const color&, const color&) noexcept;
color cross_product(const color&, const color&) noexcept;
std::ostream& operator<<(std::ostream&, const color&);
color operator*(float, const color&);

#endif