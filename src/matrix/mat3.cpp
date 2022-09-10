#include "matrix/mat3.h"

#define RANK 3
#define ELEMENTS 9

mat3::mat3() { matrix = new float[ELEMENTS]; }
mat3::mat3(float mat[ELEMENTS])
{
  matrix = new float[ELEMENTS];
  for (int i = 0; i < ELEMENTS; i++)
    matrix[i] = mat[(i % RANK) * RANK + i / RANK];
}
mat3::~mat3() { delete[] matrix; }

mat3::mat3(const mat3& m)
{
  matrix = new float[ELEMENTS];
  for (int i = 0; i < ELEMENTS; i++)
    matrix[i] = m.matrix[i];
}
mat3::mat3(mat3&& m)
  : matrix(m.matrix)
{
  m.matrix = nullptr;
}

mat3& mat3::operator=(const mat3& m)
{
  mat3 copy = m;
  std::swap(*this, copy);
  return *this;
}
mat3& mat3::operator=(mat3&& m)
{
  std::swap(this->matrix, m.matrix);
  return *this;
}

mat3 mat3::transpose() const
{
  mat3 result = *this;
  for (int y = 0; y < RANK; y++)
    for (int x = 1; x < RANK; x++)
      std::swap(result[x][y], result[y][x]);
  
  return result;
}
mat3 mat3::inverse() const
{
  mat3 result;

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
float mat3::determinant() const
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

mat3 mat3::operator*(const mat3& m) const
{
  mat3 result;
  for (int x = 0; x < RANK; x++)
    for (int y = 0; y < RANK; y++)
    {
      result[x][y] = 0;
      for (int n = 0; n < RANK; n++)
        result[x][y] += (*this)[n][y] * m[x][n];
    }
  
  return result;
}
mat3 mat3::operator*(float n) const
{
  mat3 result;
  for (int i = 0; i < ELEMENTS; i++)
    result[0][i] = matrix[i] * n;

  return result;
}
mat3 mat3::operator/(float n) const
{
  mat3 result;
  for (int i = 0; i < ELEMENTS; i++)
    result[0][i] = matrix[i] / n;

  return result;
}
mat3 mat3::operator+(const mat3& m) const
{
  mat3 result;
  for (int i = 0; i < ELEMENTS; i++)
    result[0][i] = matrix[i] + m[0][i];

  return result;
}
mat3 mat3::operator-(const mat3& m) const { return *this + -m; }
mat3 mat3::operator-() const
{
  mat3 result;
  for (int i = 0; i < ELEMENTS; i++)
    result[0][i] = -matrix[i];

  return result;
}
float* mat3::operator[](int index) const { return &matrix[index * RANK]; }

bool mat3::operator==(const mat3& m) const
{
  for (int i = 0; i < ELEMENTS; i++)
    if (matrix[i] != m[0][i])
      return false;

  return true;
}

mat3 mat3::operator*=(const mat3& m) { return *this = *this * m; }
mat3 mat3::operator*=(float n) { return *this = *this * n; }
mat3 mat3::operator/=(float n) { return *this = *this / n; }
mat3 mat3::operator+=(const mat3& m) { return *this = *this + m; }
mat3 mat3::operator-=(const mat3& m) { return *this = *this - m; }

mat2 mat3::submatrix(int xn, int yn) const
{
  mat2 result;
  for (int y = 0; y < RANK - 1; y++)
  {
    for (int x = 0; x < RANK - 1; x++)
    {
      int dx = (x < xn ? 0 : 1);
      int dy = (y < yn ? 0 : 1);

      result[x][y] = (*this)[x + dx][y + dy];
    }
  }

  return result;
}

mat3 operator*(float n, const mat3& m) { return m * n; }
std::ostream& operator<<(std::ostream& out, const mat3& m)
{
  int maxLengths[] = { 0, 0, 0 };
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
