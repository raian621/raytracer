#ifndef SCENE_H
#define SCENE_H

#include "primitives/sphere.h"
#include <vector>

class Scene
{
  public:
    std::vector<Sphere> spheres;

    Scene() {}
    void add_sphere(Sphere*);
};

#endif