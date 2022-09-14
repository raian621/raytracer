#include "camera.h"
#include "matrix/transformations.h"

Camera::Camera(int resX, int resY, float width, float height, Scene* scene)
{
  canvas = Canvas(resX, resY);
  this->position = { 0, 0, 0 };
  this->direction = { 0, 1, 0 };
  this->up = { 0, 0, 1 };
  this->right = cross(up, direction);
  this->scene = *scene;
  this->width = width;
  this->height = height;
}

void Camera::render() const
{
  for (size_t x = 0; x < canvas.width(); x++)
    for (size_t y = 0; y < canvas.height(); y++)
    {
      float ratioX = (float)x / canvas.width();
      float ratioY = (float)y / canvas.height();

      float canvasX = (2 * width * ratioX - width) / (width);
      float canvasY = (height - 2 * height * ratioY) / (height);

      vec3 rayOrigin = translate(right * canvasX) * translate(up * canvasY) * position;
      Ray r(rayOrigin, rayOrigin + direction * 100.0f);
      for (int i = 0; i < scene.spheres.size(); i++)
        r.intersections(scene.spheres[i]);
      canvas[x][y] = r.hit().int_rgb();
    }
}

void Camera::saveCanvas(const char* path, const char* filename) const { canvas.save_to_file(path, filename); }