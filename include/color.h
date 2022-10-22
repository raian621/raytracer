#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <stdint.h>
#include "vector/vec4.h"

struct color : vec4
{
  color(float r = 0, float g = 0, float b = 0, float a = 1.0);

  uint32_t int_rgb() const;
};

color clamp(const color&) noexcept;
std::ostream& operator<<(std::ostream&, const color&);

#endif