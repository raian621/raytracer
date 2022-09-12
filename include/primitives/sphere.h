#ifndef SPHERE_H
#define SPHERE_H

#include "vector/vec3.h"
#include "raytracer/ray.h"
#include "material.h"

struct Sphere
{
  vec3 position;
  float radius;
  Material material;

  Sphere(vec3 position, float radius, const Material& material);
  void intersections(Ray*) const;
};

#endif