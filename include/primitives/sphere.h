#ifndef SPHERE_H
#define SPHERE_H

#include "vector/vec3.h"
#include "raytracer/ray.h"
#include "material.h"

struct Sphere
{
  vec3 position;
  vec3 rotation;
  
  float radius;
  Material material;

  Sphere(vec3 position, float radius, const Material& material);
  void intersections(Ray*) const;
  vec3 normal_at(const vec3&) const;
};

#endif