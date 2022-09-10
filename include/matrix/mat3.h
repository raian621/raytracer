#ifndef MAT3_H
#define MAT3_H

#include "matrix/mat2.h"

class mat3
{
  public:
    mat3();
    mat3(float[9]);
    ~mat3();

    mat3(const mat3&);
    mat3(mat3&&);

    mat3& operator=(const mat3&);
    mat3& operator=(mat3&&);

    mat3 transpose() const;
    mat3 inverse() const;
    float determinant() const;

    mat3 operator*(const mat3&) const;
    mat3 operator*(float) const;
    mat3 operator/(float) const;
    mat3 operator+(const mat3&) const;
    mat3 operator-(const mat3&) const;
    mat3 operator-() const;
    float* operator[](int) const;
    
    bool operator==(const mat3&) const;
    mat3 operator*=(const mat3&);
    mat3 operator*=(float);
    mat3 operator/=(float);
    mat3 operator+=(const mat3&);
    mat3 operator-=(const mat3&);

  private:
    float *matrix;
    mat2 submatrix(int, int) const;
};

mat3 operator*(float, const mat3&);
std::ostream& operator<<(std::ostream&, const mat3&);

#endif