#include "matrix/mat4.h"

#define RANK 4
#define ELEMENTS 16

mat4::mat4()
{ 
  matrix = new float[ELEMENTS];
  for (int x = 0; x < RANK; x++)
    for (int y = 0; y < RANK; y++)
      (*this)[x][y] = (x == y ? 1 : 0);
}
mat4::mat4(float mat[ELEMENTS])
{
  matrix = new float[ELEMENTS];
  for (int i = 0; i < ELEMENTS; i++)
    matrix[i] = mat[(i % RANK) * RANK + i / RANK];
}
mat4::~mat4() { delete[] matrix; }

mat4::mat4(const mat4& m)
{
  matrix = new float[ELEMENTS];
  for (int i = 0; i < ELEMENTS; i++)
    matrix[i] = m.matrix[i];
}
mat4::mat4(mat4&& m)
  : matrix(m.matrix)
{
  m.matrix = nullptr;
}

mat4& mat4::operator=(const mat4& m)
{
  mat4 copy = m;
  std::swap(*this, copy);
  return *this;
}
mat4& mat4::operator=(mat4&& m)
{
  std::swap(this->matrix, m.matrix);
  return *this;
}

mat4 mat4::transpose() const
{
  mat4 result = *this;
  for (int y = 0; y < RANK; y++)
    for (int x = 1; x < RANK; x++)
      std::swap(result[x][y], result[y][x]);
  
  return result;
}
mat4 mat4::inverse() const
{
  mat4 result;
  
  for (int x = 0; x < RANK; x++)
  {
    for (int y = 0; y < RANK; y++)
    {
      if ((x + y) % 2)
        result[y][x] = -(submatrix(x, y).determinant());
      else
        result[y][x] = submatrix(x, y).determinant();
    }
  }
  return result / determinant();
}
float mat4::determinant() const
{
  float det = 0;
  for (int i = 0; i < RANK; i++)
  {
    if (i % 2)
      det -= (*this)[i][0] * submatrix(i, 0).determinant();
    else
      det += (*this)[i][0] * submatrix(i, 0).determinant();
  }

  return det;
}

mat4 mat4::operator*(const mat4& m) const
{
  mat4 result;
  for (int x = 0; x < RANK; x++)
    for (int y = 0; y < RANK; y++)
    {
      result[x][y] = 0;
      for (int n = 0; n < RANK; n++)
        result[x][y] += (*this)[n][y] * m[x][n];
    }
  
  return result;
}
vec4 mat4::operator*(const vec4& vector) const
{
  return {
    (*this)[0][0] * vector.x + (*this)[1][0] * vector.y + (*this)[2][0] * vector.z + (*this)[3][0] * vector.w,
    (*this)[0][1] * vector.x + (*this)[1][1] * vector.y + (*this)[2][1] * vector.z + (*this)[3][1] * vector.w,
    (*this)[0][2] * vector.x + (*this)[1][2] * vector.y + (*this)[2][2] * vector.z + (*this)[3][2] * vector.w,
    (*this)[0][3] * vector.x + (*this)[1][3] * vector.y + (*this)[2][3] * vector.z + (*this)[3][3] * vector.w
  };
}
vec3 mat4::operator*(const vec3& vector) const
{
  return {
    (*this)[0][0] * vector.x + (*this)[1][0] * vector.y + (*this)[2][0] * vector.z + (*this)[3][0],
    (*this)[0][1] * vector.x + (*this)[1][1] * vector.y + (*this)[2][1] * vector.z + (*this)[3][1],
    (*this)[0][2] * vector.x + (*this)[1][2] * vector.y + (*this)[2][2] * vector.z + (*this)[3][2]
  };
}
mat4 mat4::operator*(float n) const
{
  mat4 result;
  for (int i = 0; i < ELEMENTS; i++)
    result[0][i] = matrix[i] * n;

  return result;
}
mat4 mat4::operator/(float n) const
{
  mat4 result;
  for (int i = 0; i < ELEMENTS; i++)
    result[0][i] = matrix[i] / n;

  return result;
}
mat4 mat4::operator+(const mat4& m) const
{
  mat4 result;
  for (int i = 0; i < ELEMENTS; i++)
    result[0][i] = matrix[i] + m[0][i];

  return result;
}
mat4 mat4::operator-(const mat4& m) const { return *this + -m; }
mat4 mat4::operator-() const
{
  mat4 result;
  for (int i = 0; i < ELEMENTS; i++)
    result[0][i] = -matrix[i];

  return result;
}
float* mat4::operator[](int index) const { return &matrix[index * RANK]; }

bool mat4::operator==(const mat4& m) const
{
  for (int i = 0; i < ELEMENTS; i++)
    if (matrix[i] != m[0][i])
      return false;

  return true;
}
mat4 mat4::operator*=(const mat4& m) { return *this = *this * m; }
mat4 mat4::operator*=(float n) { return *this = *this * n; }
mat4 mat4::operator/=(float n) { return *this = *this / n; }
mat4 mat4::operator+=(const mat4& m) { return *this = *this + m; }
mat4 mat4::operator-=(const mat4& m) { return *this = *this - m; }


mat3 mat4::submatrix(int xn, int yn) const
{
  mat3 result;
  for (int x = 0; x < RANK - 1; x++)
  {
    for (int y = 0; y < RANK - 1; y++)
    {
      int dx = (x < xn ? 0 : 1);
      int dy = (y < yn ? 0 : 1);
      result[x][y] = (*this)[x + dx][y + dy];
    }
  }
  return result;
}

mat4 operator*(float n, const mat4& m) { return m * n; }
std::ostream& operator<<(std::ostream& out, const mat4& m)
{
  int maxLengths[] = { 0, 0, 0, 0 };
  std::string values[ELEMENTS];

  for (int y = 0; y < RANK; y++)
  {
    for (int x = 0; x < RANK; x++)
    {
      std::string value = std::to_string(m[x][y]);
      values[RANK * y + x] = value;
      
      if (maxLengths[x] < value.length())
        maxLengths[x] = value.length();
    }
  }

  for (int i = 0; i < ELEMENTS; i++)
  {
    if (i % RANK == 0)
      out << "| ";

    out << values[i];
    for (int j = values[i].length(); j < maxLengths[i % RANK] + 1; j++)
      out << ' ';

    if (i % RANK == RANK - 1)
      if (i < ELEMENTS)
        out << "|\n";
      else
        out << "|";
  }

  return out;
}