#include "raytracer/ray.h"
#include "primitives/sphere.h"
#include <cmath>
#include <iostream>

SphereIntersection::SphereIntersection(float t, const Sphere* source)
  : Intersection(t)
{
  this->source = source;
}

Intersection::Intersection(float t)
{
  this->t = t;
}

bool Intersection::operator==(const Intersection& i) { return this->t == i.t; }
bool Intersection::operator<=(const Intersection& i) { return this->t <= i.t; }
bool Intersection::operator>=(const Intersection& i) { return this->t >= i.t; }
bool Intersection::operator<(const Intersection& i) { return this->t > i.t; }
bool Intersection::operator>(const Intersection& i) { return this->t > i.t; }

Ray::Ray(const vec3& origin, const vec3& direction)
{
  this->origin = origin;
  this->direction = direction;
}
void Ray::intersections(const Sphere* volume)
{
  volume->intersections(this);
}
void Ray::sortIntersections()
{
  for (int i = 1; i < sphereIntersections.size(); i++)
    if (sphereIntersections[0] > sphereIntersections[i])
      std::swap(sphereIntersections[0], sphereIntersections[i]);
}
color Ray::hit()
{
  sortIntersections();
  if (sphereIntersections.size() == 0)
    return color(0.3f, 0.3f, 0.3f);

  return sphereIntersections.back().source->material.materialColor;
}