#include <iostream>
#include "color.h"
#include "vector/vec2.h"
#include "canvas.h"
#include "matrix/mat4.h"

int main()
{
  int width(2000), height(3000);
  mat4 mat;
  color c1(1, 0.5, 0.25 );
  color c2 = clamp(c1 * 2);
  color c3(0, 0, 0);
  Canvas canvas(width, height);

  vec2 center = { canvas.width() / 2, canvas.height() / 2 };
  vec2 coord;
  float radius = width * 0.4f;

  for(coord.x = 0; coord.x < canvas.width(); coord.x++)
    for (coord.y = 0; coord.y < canvas.height(); coord.y++)
      canvas[(int)coord.x][(int)coord.y] = c1.int_rgb();

  for(coord.x = 0; coord.x < canvas.width(); coord.x++)
    for (coord.y = 0; coord.y < canvas.height(); coord.y++)
      if ((center - coord).magnitude() <= radius)
        canvas[(int)coord.x][(int)coord.y] = c3.int_rgb();
      else
        if ((int)coord.y / 10 % 2)
          canvas[(int)coord.x][(int)coord.y] = c2.int_rgb();
        else if ((int)coord.x / 25 % 2)
          canvas[(int)coord.x][(int)coord.y] = c2.int_rgb() / 2;

  canvas.save_to_file("../out", "plain.ppm");
}