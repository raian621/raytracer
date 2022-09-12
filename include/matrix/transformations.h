#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "mat4.h" 

mat4 scale(float, float, float);
mat4 scale(vec4);
mat4 scale(vec3);
mat4 scale(float);
mat4 scale_x(float);
mat4 scale_y(float);
mat4 scale_y(float);

mat4 translate(float, float, float);
mat4 translate(vec4);
mat4 translate(vec3);

mat4 rotate_x(float);
mat4 rotate_y(float);
mat4 rotate_z(float);

mat4 shear(float, float, float, float);

#endif