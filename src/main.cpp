#include <iostream>
#include "material.h"
#include "primitives/sphere.h"
#include "camera.h"
#include "scene.h"

int main()
{
  Scene scene;
  Material material1(color(0.8f, 0.2f, 0.2f));
  Material material2(color(0.8f, 0.8f, 0.2f));
  Sphere sphere1(vec3(-.2, 0, 0), 0.4f, material1);
  Sphere sphere2(vec3(0.2, 0, 0), 0.2f, material2);

  scene.add_sphere(&sphere1);
  scene.add_sphere(&sphere2);
  Camera camera(200, 200, 1.0f, 1.0f, &scene);
  camera.position = { 0, -3, 0 };
  camera.render();

  camera.saveCanvas("../out", "simple_spheres.ppm");
}