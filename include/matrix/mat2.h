#ifndef MAT2_H
#define MAT2_H

#include <iostream>

class mat2
{
  public:
    mat2();
    mat2(float[4]);
    ~mat2();

    mat2(const mat2&);
    mat2(mat2&&);

    mat2& operator=(const mat2&);
    mat2& operator=(mat2&&);

    mat2 transpose() const;
    mat2 inverse() const;
    float determinant() const;

    mat2 operator*(const mat2&) const;
    mat2 operator*(float) const;
    mat2 operator/(float) const;
    mat2 operator+(const mat2&) const;
    mat2 operator-(const mat2&) const;
    mat2 operator-() const;
    float* operator[](int) const;
    
    bool operator==(const mat2&) const;
    mat2 operator*=(const mat2&);
    mat2 operator*=(float);
    mat2 operator/=(float);
    mat2 operator+=(const mat2&);
    mat2 operator-=(const mat2&);
  
  private:
    float *matrix;
};

mat2 operator*(float, const mat2&);
std::ostream& operator<<(std::ostream&, const mat2&);

#endif