#include <iostream>
#include "vector/vec3.h"

int main()
{
  vec3 v1 = { 1, 2, 3 };
  v1 += (vec3){ 1, 2, 3 };
  std::cout << v1 << std::endl;
}