#include "raytracer/ray.h"
#include "primitives/sphere.h"
#include "matrix/transformations.h"
#include <cmath>

Intersection::Intersection(float t)
{
  this->t = t;
}

bool Intersection::operator==(const Intersection& i) { return this->t == i.t; }
bool Intersection::operator<=(const Intersection& i) { return this->t <= i.t; }
bool Intersection::operator>=(const Intersection& i) { return this->t >= i.t; }
bool Intersection::operator<(const Intersection& i) { return this->t > i.t; }
bool Intersection::operator>(const Intersection& i) { return this->t > i.t; }

SphereIntersection::SphereIntersection(float t, const Sphere* source)
  : Intersection(t)
{
  this->source = source;
}

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
  for (size_t i = 1; i < sphereIntersections.size(); i++)
    if (sphereIntersections[0] > sphereIntersections[i])
      std::swap(sphereIntersections[0], sphereIntersections[i]);
}
Ray Ray::transform(const mat4& transformation)
{
  return { transformation * origin, transformation * direction };
}
color Ray::hit()
{
  sortIntersections();
  if (sphereIntersections.size() == 0)
    return color(0.3f, 0.3f, 0.3f);
  
  SphereIntersection si = sphereIntersections[0];
  Sphere s = *si.source;
  Ray localRay = transform(s.transform.inverse());

  vec3 normal = s.normal_at(localRay.origin + localRay.direction * si.t);
  color normalColor = { normal.x / 2.0f + 0.5f, normal.y / 2.0f + 0.5f, normal.z / 2.0f + 0.5f };
  return normalColor;
  // return sphereIntersections[0].source->material.materialColor;
}
