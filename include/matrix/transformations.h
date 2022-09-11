#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "mat4.h" 

mat4 scale(float, float, float);
mat4 scale(float);
mat4 scale_x(float);
mat4 scale_y(float);
mat4 scale_y(float);
mat4 translation(float, float, float);
mat4 rotation_x(float);
mat4 rotation_y(float);
mat4 rotation_z(float);
mat4 shear(float, float, float, float);

#endif