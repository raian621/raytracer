#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"

struct Material
{
  color materialColor;

  Material(const color&);
  Material() {};
};

#endif