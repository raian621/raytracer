#include "raytracer/ray.h"
#include "primitives/sphere.h"
#include "matrix/transformations.h"
#include <cmath>

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
  SphereIntersection si = sphereIntersections[0];
  Sphere s = *si.source;
  mat4 rotation = rotate_x(s.rotation.x) * rotate_y(s.rotation.y) * rotate_z(s.rotation.z);
  vec3 normal = rotation * s.normal_at(
    origin + si.t * direction
  );
  color color(normal.x / 2 + 0.5, normal.y / 2 + 0.5, normal.z / 2 + 0.5);
  return color;
}