#include <iostream>
#include "material.h"
#include "primitives/sphere.h"
#include "camera.h"
#include "scene.h"
#include "matrix/transformations.h"

#include <math.h>

int main()
{
  Scene scene;
  Material material(color(0.8f, 0.2f, 0.2f));
  Sphere sphere(vec3(0, 0, 0), 0.8f, material);

  scene.add_sphere(&sphere);
  Camera camera(720, 720, 1.0f, 1.0f, &scene);
  
  camera.position = { 0, -3, 0 };
  camera.up = cross(camera.direction, camera.right);

  int framesPerRotation = 24 * 5;
  int maxDigits = log10(framesPerRotation);
  for (int i = 0; i < framesPerRotation; i++)
  {
    sphere.rotation.z = (2 * M_PI * i) / framesPerRotation;
    std::cout << sphere.rotation << std::endl;
    camera.render();
    std::string filename = "normal_sphere";
    int digits = (i ? (int)log10(i) : 0);
    std::cout << digits << std::endl;

    for (int j = digits; j < maxDigits; j++)
      filename.append("0");
    filename.append(std::to_string(i));
    filename.append(".ppm");

    camera.saveCanvas("../out/normal_sphere", filename.c_str());
  }
}