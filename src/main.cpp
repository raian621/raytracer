#include <iostream>
#include "color.h"
#include "vector/vec2.h"
#include "canvas.h"
#include "matrix/mat4.h"
#include "matrix/transformations.h"

#define PI 3.14159265

int main()
{
  int width(100), height(100);
  Canvas canvas(width, height);
  float radius = width * 0.40;
  vec3 initialPos = { 0, radius };
  vec3 center = { width / 2.0f, height / 2.0f };
  
  for (int x = 0; x < width; x++)
    for (int y = 0; y < height; y++)
      canvas[x][y] = 0; // black color
  
  for (float angle = 0.0f; angle < 2 * PI; angle += PI / 6)
  {
    vec3 pos = translate(center.x, center.y, 0) * rotate_z(angle) *  initialPos;
    canvas[(int)pos.x][(int)pos.y] = 0xffffff;
  }

  canvas.save_to_file("../out", "clock.ppm");
}