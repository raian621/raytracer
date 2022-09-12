#ifndef RAY_H
#define RAY_H

#include <vector>
#include "vector/vec3.h"
#include "color.h"

struct Sphere;

struct Intersection
{
  float t;
  
  Intersection(float);

  bool operator==(const Intersection&);
  bool operator<=(const Intersection&);
  bool operator>=(const Intersection&);
  bool operator<(const Intersection&);
  bool operator>(const Intersection&);
};

struct SphereIntersection : Intersection
{
  const Sphere* source;

  SphereIntersection(float, const Sphere*);
};

struct Ray
{
  vec3 origin;
  vec3 direction;
  std::vector<SphereIntersection> sphereIntersections;

  Ray(const vec3&, const vec3&);
  void intersections(const Sphere*);
  void sortIntersections();
  color hit();
};

#endif