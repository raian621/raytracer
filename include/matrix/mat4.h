#ifndef MAT4_H
#define MAT4_H

#include "matrix/mat3.h"

class mat4
{
  public:
    mat4();
    mat4(float[16]);
    ~mat4();

    mat4(const mat4&);
    mat4(mat4&&);

    mat4& operator=(const mat4&);
    mat4& operator=(mat4&&);

    mat4 transpose() const;
    mat4 inverse() const;
    float determinant() const;

    mat4 operator*(const mat4&) const;
    mat4 operator*(float) const;
    mat4 operator/(float) const;
    mat4 operator+(const mat4&) const;
    mat4 operator-(const mat4&) const;
    mat4 operator-() const;
    float* operator[](int) const;

    bool operator==(const mat4&) const;
    mat4 operator*=(const mat4&);
    mat4 operator*=(float);
    mat4 operator/=(float);
    mat4 operator+=(const mat4&);
    mat4 operator-=(const mat4&);
    
  private:
    float *matrix;
    mat3 submatrix(int, int) const;
};

mat4 operator*(float, const mat4&);
std::ostream& operator<<(std::ostream&, const mat4&);

#endif