#include <iostream>
#include "vector/vec3.h"
#include "canvas.h"

int main()
{
  Canvas canvas(30, 30);
  for (int x = 0; x < canvas.width(); x++)
    for (int y = 0; y < canvas.width(); y++)
      canvas[x][y] = 0x745400;

  for (int x = 0; x < canvas.width(); x++)
    canvas[x][10] = 0xffffff;

  canvas.save_to_file("../out", "plain.ppm");
}