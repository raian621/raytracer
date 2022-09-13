#include "matrix/transformations.h"
#include <math.h>

mat4 scale(float x, float y, float z)
{
  float matrix[] = { 
    x, 0, 0, 0,
    0, y, 0, 0,
    0, 0, z, 0,
    0, 0, 0, 1 
  };

  return mat4(matrix);
}
mat4 scale(float xyz) { return scale(xyz, xyz, xyz); }
mat4 scale(const vec3& vector) { return scale(vector.x, vector.y, vector.z); }
mat4 scale(const vec4& vector) { return scale(vector.x, vector.y, vector.z); }
mat4 scale_x(float x) { return scale(x, 0, 0); }
mat4 scale_y(float y) { return scale(0, y, 0); }
mat4 scale_z(float z) { return scale(0, 0, z); }

mat4 translate(float x, float y, float z)
{
  float matrix[] = {
    1, 0, 0, x,
    0, 1, 0, y,
    0, 0, 1, z,
    0, 0, 0, 1
  };

  return mat4(matrix);
}
mat4 translate(const vec3& vector) { return translate(vector.x, vector.y, vector.z); }
mat4 translate(const vec4& vector) { return translate(vector.x, vector.y, vector.z); }

mat4 rotate_x(float x)
{
  float matrix[] = {
    1, 0,          0,         0,
    0, cosf32(x), -sinf32(x), 0,
    0, sinf32(x),  cosf32(x), 0,
    0, 0,          0,         1
  };

  return mat4(matrix);
}
mat4 rotate_y(float y)
{
  float matrix[] = {
     cosf32(y), 0, sinf32(y), 0,
     0,         1, 0,         0,
    -sinf32(y), 0, cosf32(y), 0,
     0,         0, 0,         1
  };

  return mat4(matrix);
}
mat4 rotate_z(float z)
{
  float matrix[] = {
    cosf32(z), -sinf32(z), 0, 0,
    sinf32(z),  cosf32(z), 0, 0,
    0,          0,         1, 0,
    0,          0,         0, 1
  };

  return mat4(matrix);
}

mat4 shear(float xy, float xz, float yx, float yz, float zx, float zy)
{
  float matrix[] = {
    1,  xy, xz, 0,
    yx, 1,  yz, 0,
    zx, zy, 1,  0,
    0,  0,  0,  1
  };

  return matrix;
}