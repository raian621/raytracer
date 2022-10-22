#ifndef TESTS_H
#define TESTS_H

#include <iostream>

bool assert_equals(float a, float b, float epsilon)
{
	float diff;
	if (a > b)
		diff = a - b;
	else
		diff = b - a;

	return diff < epsilon;
}

#ifdef VEC_TESTS
#include "vector/vec2.h"
#include "vector/vec3.h"
#include "vector/vec4.h"

bool assert_equals(const vec2& a, const vec2& b, float epsilon)
{
  return assert_equals(a.x, b.x, epsilon) 
		&& assert_equals(a.y, b.y, epsilon);
}

bool assert_equals(const vec3& a, const vec3& b, float epsilon)
{
	return assert_equals(a.x, b.x, epsilon) 
    && assert_equals(a.y, b.y, epsilon)
    && assert_equals(a.z, b.z, epsilon);
}

bool assert_equals(const vec4& a, const vec4& b, float epsilon)
{
	return assert_equals(a.x, b.x, epsilon) 
		&& assert_equals(a.y, b.y, epsilon)
		&& assert_equals(a.z, b.z, epsilon)
		&& assert_equals(a.w, b.w, epsilon);
}

void test_vec2()
{
  vec2 v1 = { 1, 2 };
	vec2 v2 = { 2, 3 };

	vec2 result = v1 * 20.0f;
	vec2 solution = { 20.0, 40.0 };

	std::cout << "\n================================\n";
	std::cout << "vec2 tests:\n";
	std::cout << "================================\n";

	printf("[%c] scalar multiplication test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));
	
	result = result / 20.0f;
	solution = { 1.0, 2.0 };
	printf("[%c] scalar division test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result *= 20.0f;
	solution = { 20.0, 40.0 };
	printf("[%c] scalar multiplication assignment test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result /= 20.0f;
	solution = { 1.0, 2.0 };
	printf("[%c] scalar division assignment test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result = v1 + v2;
	solution = { 3.0, 5.0 };
	printf("[%c] vector add test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result = v1 - v2;
	solution = { -1.0, -1.0 };
	printf("[%c] vector subtract test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result += v1;
	solution = { 0.0, 1.0 };
	printf("[%c] vector add assignment test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result -= v2;
	solution = { -2.0, -2.0 };
	printf("[%c] vector subtract assignment test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	float f_result = dot(v1, v2);
	float f_solution = 8.0f;
	printf("[%c] dot product test\n",
		(assert_equals(f_result, f_solution, 0.0001f) ? '+' : ' '));

	result = v1;
	printf("[%c] assignment test\n",
		(assert_equals(result, v1, 0.0001f) ? '+' : ' '));
}

void test_vec3()
{
	vec3 v1 = { 1, 2, 3 };
	vec3 v2 = { 2, 3, 4 };

	vec3 result = v1 * 20.0f;
	vec3 solution = { 20.0, 40.0, 60.0 };

	std::cout << "\n================================\n";
	std::cout << "vec3 tests:\n";
	std::cout << "================================\n";

	printf("[%c] scalar multiplication test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));
	
	result = result / 20.0f;
	solution = { 1.0, 2.0, 3.0 };
	printf("[%c] scalar division test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result *= 20.0f;
	solution = { 20.0, 40.0, 60.0 };
	printf("[%c] scalar multiplication assignment test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result /= 20.0f;
	solution = { 1.0, 2.0, 3.0 };
	printf("[%c] scalar division assignment test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result = v1 + v2;
	solution = { 3.0, 5.0, 7.0 };
	printf("[%c] vector add test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result = v1 - v2;
	solution = { -1.0, -1.0, -1.0 };
	printf("[%c] vector subtract test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result += v1;
	solution = { 0.0, 1.0, 2.0 };
	printf("[%c] vector add assignment test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result -= v2;
	solution = { -2.0, -2.0, -2.0 };
	printf("[%c] vector subtract assignment test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	float f_result = dot(v1, v2);
	float f_solution = 20.0f;
	printf("[%c] dot product test\n",
		(assert_equals(f_result, f_solution, 0.0001f) ? '+' : ' '));

	result = v1;
	printf("[%c] assignment test\n",
		(assert_equals(result, v1, 0.0001f) ? '+' : ' '));

	result = cross(v1, v2);
	solution = { -1, 2, -1 };

	printf("[%c] cross product test\n",
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));
}

void test_vec4()
{
	vec4 v1 = { 1, 2, 3, 4 };
	vec4 v2 = { 2, 3, 4, 5 };

	vec4 result = v1 * 20.0f;
	vec4 solution = { 20.0, 40.0, 60.0, 80.0 };

	std::cout << "\n================================\n";
	std::cout << "vec4 tests:\n";
	std::cout << "================================\n";

	printf("[%c] scalar multiplication test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));
	
	result = result / 20.0f;
	solution = { 1.0, 2.0, 3.0, 4.0 };
	printf("[%c] scalar division test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result *= 20.0f;
	solution = { 20.0, 40.0, 60.0, 80.0 };
	printf("[%c] scalar multiplication assignment test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result /= 20.0f;
	solution = { 1.0, 2.0, 3.0, 4.0 };
	printf("[%c] scalar division assignment test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result = v1 + v2;
	solution = { 3.0, 5.0, 7.0, 9.0 };
	printf("[%c] vector add test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result = v1 - v2;
	solution = { -1.0, -1.0, -1.0, -1.0 };
	printf("[%c] vector subtract test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result += v1;
	solution = { 0.0, 1.0, 2.0, 3.0 };
	printf("[%c] vector add assignment test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	result -= v2;
	solution = { -2.0, -2.0, -2.0, -2.0 };
	printf("[%c] vector subtract assignment test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	float f_result = dot(v1, v2);
	float f_solution = 40.0f;
	printf("[%c] dot product test\n",
		(assert_equals(f_result, f_solution, 0.0001f) ? '+' : ' '));

	result = v1;
	printf("[%c] assignment test\n",
		(assert_equals(result, v1, 0.0001f) ? '+' : ' '));

	result = cross(v1, v2);
	solution = { -1, 2, -1, 1 };

	printf("[%c] cross product test\n",
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));
}

#endif
#ifdef MAT_TESTS
#include "matrix/mat2.h"
#include "matrix/mat3.h"
#include "matrix/mat4.h"

bool assert_equals(const mat2& a, const mat2& b, float epsilon)
{
	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 2; y++)
			if (!assert_equals(a[x][y], b[x][y], epsilon))
				return false;

	return true;
}
bool assert_equals(const mat3& a, const mat3& b, float epsilon)
{
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			if (!assert_equals(a[x][y], b[x][y], epsilon))
				return false;

	return true;
}
bool assert_equals(const mat4& a, const mat4& b, float epsilon)
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			if (!assert_equals(a[x][y], b[x][y], epsilon))
				return false;

	return true;
}

void test_mat2()
{
	float f1[4] = {
		1, 2,
		3, 4
	};

	float f2[4] = {
		2, 3,
		4, 5
	};

	mat2 m1 { f1 };
	mat2 m2 { f2 };

	mat2 result = m1;
	std::cout << "\n================================\n";
	std::cout << "mat2 tests:\n";
	std::cout << "================================\n";

	printf("[%c] assignment test\n", 
		(assert_equals(result, m1, 0.0001f) ? '+' : ' '));

	float f_solution = -2.0f;
	float f_result = m1.determinant();

	printf("[%c] determinant test\n", 
		(assert_equals(f_result, f_solution, 0.0001f) ? '+' : ' '));

	float f3[4] = {
		1, 3,
		2, 4
	};
	mat2 solution { f3 };
	result = m1.transpose();

	printf("[%c] transpose test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	
	solution[0][0] = -2;
	solution[1][0] = 1;
	solution[0][1] = 3.0f/2.0f;
	solution[1][1] = -1.0f/2.0f;
	result = m1.inverse();

	printf("[%c] inverse test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));

	solution[0][0] = 10;
	solution[1][0] = 13;
	solution[0][1] = 22;
	solution[1][1] = 29;
	result = m1 * m2;

	printf("[%c] matrix multiplication test\n", 
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));
}

void test_mat3()
{
	float f1[9] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};

	float f2[9] = {
		2, 3, 4,
		5, 6, 7,
		8, 9, 11,
	};

	mat3 m1 { f1 };
	mat3 m2 { f2 };

	mat3 result = m1;
	std::cout << "\n================================\n";
	std::cout << "mat3 tests:\n";
	std::cout << "================================\n";

	printf("[%c] assignment test\n", 
		(assert_equals(result, m1, 0.0001f) ? '+' : ' '));

	float f3[9] = {
		-1.0f,        -1.0f,         1.0f,
		-1.0f / 3.0f, 10.0f / 3.0f, -2.0f,
		 1.0f,        -2.0f,         1.0f
	};

	result = m2.inverse();
	mat3 solution{ f3 };

	printf("[%c] inverse test\n",
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));
}

void test_mat4()
{
	float f1[16] = {
		 1,  2,  3,  4,
		 5,  6,  7,  8,
		 9, 10, 11, 12,
		13, 14, 15, 16
	};

	float f2[16] = {
		  2,  3,  4,  5,
		  6,  7,  9,  9,
		 10,  1, 12, 13,
		 14, 15, 16, 17
	};


	mat4 m1 { f1 };
	mat4 m2 { f2 };


	mat4 result = m1;
	std::cout << "\n================================\n";
	std::cout << "mat4 tests:\n";
	std::cout << "================================\n";

	std::cout << m2 << std::endl;
	printf("[%c] assignment test\n",
		(assert_equals(result, m1, 0.0001f) ? '+' : ' '));

	float f_solution = -360.0f;
	float f_result = m2.determinant();

	printf("[%c] determinant test\n",
		(assert_equals(f_result, f_solution, 0.0001f) ? '+' : ' '));

	float f3[16] = {
		-49.0f / 180.0f, -1.0f / 3.0f,  1.0f / 15.0f,  37.0f / 180.0f,
		 1.0f / 30.0f,    0.0f,        -1.0f / 10.0f,  1.0f / 15.0f
		-2.0f / 3.0f,     1.0f,         0.0f,         -1.0 / 3.0f,
		37.0f / 45.0f,   -2.0f / 3.0f,  1.0f / 30.0f,  13.0f / 90.0f
	};
	mat4 solution{ f3 };
	result = m2.inverse();

	std::cout << solution.inverse() << std::endl;

	printf("[%c] inverse test\n",
		(assert_equals(result, solution, 0.0001f) ? '+' : ' '));
}
#endif

void run_tests()
{
	#ifdef VEC_TESTS
	test_vec2();
	test_vec3();
	test_vec4();
	#endif
	#ifdef MAT_TESTS
	test_mat2();
	test_mat3();
	test_mat4();
	#endif
}

#endif