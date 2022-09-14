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
  Sphere sphere1(vec3(-0.3, 2, 0.2), 0.2f, material);
  Sphere sphere2(vec3(0.1, 1, 0.0), 0.5f, material);
  Sphere sphere3(vec3(-0.4, 2, -0.1), 0.1f, material);
  
  scene.add_sphere(&sphere1);
  scene.add_sphere(&sphere2);
  scene.add_sphere(&sphere3);
  Camera camera(720, 720, 1.0f, 1.0f, &scene);
  
  camera.position = { 0, -2, 0 };
  camera.up = cross(camera.direction, camera.right);

  camera.render();

  camera.saveCanvas("../out", "reg_sphere.ppm");
}