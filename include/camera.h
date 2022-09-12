#ifndef CAMERA_H
#define CAMERA_H

#include "color.h"
#include "canvas.h"
#include "scene.h"
#include <vector/vec3.h>

class Camera
{
  public:
    vec3 position;
    vec3 direction; // also normal vector of canvas
    vec3 up;
    vec3 right;

    Camera(int, int, float, float, Scene*);
    void render() const;
    void saveCanvas(const char*, const char*) const;

  private:
    Canvas canvas;
    Scene scene;
    float width;
    float height;
};

#endif