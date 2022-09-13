#include "primitives/sphere.h"
#include "material.h"
#include "matrix/transformations.h"
#include <cmath>

Sphere::Sphere(vec3 position, float radius, const Material& material)
{
  this->position = position;
  this->radius = radius;
  this->material = material;
  this->rotation = { 0, 0, 0 };
}

void Sphere::intersections(Ray* r) const
{
  vec3 sphereToRay = r->origin - this->position;
  float a = dot(r->direction, r->direction);
  float b = 2 * dot(r->direction, sphereToRay);
  float c = dot(sphereToRay, sphereToRay) - radius;

  float determinant = b * b - 4 * a * c;

  if (determinant >= 0)
  {
    float t1 = (-b - sqrtf32(determinant)) / (2 * a);
    float t2 = (-b + sqrtf32(determinant)) / (2 * a);

    if (t1 >= 0)
      r->sphereIntersections.push_back(SphereIntersection(t1, this));
    if (t2 >= 0)
      r->sphereIntersections.push_back(SphereIntersection(t2, this));
  }
}

vec3 Sphere::normal_at(const vec3& point) const
{
  return (point - position).normalize();
}