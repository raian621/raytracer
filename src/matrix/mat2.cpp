#include "matrix/mat2.h"

#define RANK 2
#define ELEMENTS 4

mat2::mat2()
{ 
  matrix = new float[ELEMENTS]; 
  for (int x = 0; x < RANK; x++)
    for (int y = 0; y < RANK; y++)
      (*this)[x][y] = (x == y ? 1 : 0);
}
mat2::mat2(float mat[ELEMENTS])
{
  matrix = new float[ELEMENTS];
  for (int i = 0; i < ELEMENTS; i++)
    matrix[i] = mat[(i % RANK) * RANK + i / RANK];
}
mat2::~mat2() { delete[] matrix; }

mat2::mat2(const mat2& m)
{
  matrix = new float[ELEMENTS];
  for (int i = 0; i < ELEMENTS; i++)
    matrix[i] = m.matrix[i];
}
mat2::mat2(mat2&& m)
  : matrix(m.matrix)
{
  m.matrix = nullptr;
}

mat2& mat2::operator=(const mat2& m)
{
  mat2 copy = m;
  std::swap(*this, copy);
  return *this;
}
mat2& mat2::operator=(mat2&& m)
{
  std::swap(this->matrix, m.matrix);
  return *this;
}

mat2 mat2::transpose() const
{
  mat2 result = *this;
  std::swap(result[0][1], result[1][0]);

  return result;
}
mat2 mat2::inverse() const
{
  float det = determinant();
  if (det == 0) return *this;
  mat2 result;
  for (int x = 0; x < RANK; x++)
  {
    for (int y = 0; y < RANK; y++)
    {
      if ((x + y) % 2)
        result[y][x] = -(*this)[(x + 1) % 2][(y + 1) % 2];
      else
        result[y][x] = (*this)[(x + 1) % 2][(y + 1) % 2];
    }
  }
  return result / det;
}
float mat2::determinant() const
{
  return ((*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0]);
}

mat2 mat2::operator*(const mat2& m) const
{
  mat2 result;
  for (int x = 0; x < RANK; x++)
    for (int y = 0; y < RANK; y++)
    {
      result[x][y] = 0;
      for (int n = 0; n < RANK; n++)
        result[x][y] += (*this)[n][y] * m[x][n];
    }
  
  return result;
}
mat2 mat2::operator*(float n) const
{
  mat2 result;
  for (int i = 0; i < ELEMENTS; i++)
    result[0][i] = matrix[i] * n;

  return result;
}
mat2 mat2::operator/(float n) const
{
  mat2 result;
  for (int i = 0; i < ELEMENTS; i++)
    result[0][i] = matrix[i] / n;

  return result;
}
mat2 mat2::operator+(const mat2& m) const
{
  mat2 result;
  for (int i = 0; i < ELEMENTS; i++)
    result[0][i] = matrix[i] + m[0][i];

  return result;
}
mat2 mat2::operator-(const mat2& m) const { return *this + -m; }
mat2 mat2::operator-() const
{
  mat2 result;
  for (int i = 0; i < ELEMENTS; i++)
    result[0][i] = -matrix[i];

  return result;
}
float* mat2::operator[](int index) const
{
  return &(matrix[index * RANK]);
}

bool mat2::operator==(const mat2& m) const
{
  for (int i = 0; i < ELEMENTS; i++)
    if (matrix[i] != m[0][i])
      return false;

  return true;
}
mat2 mat2::operator*=(const mat2& m) { return *this = *this * m; }
mat2 mat2::operator*=(float n) { return *this = *this * n; }
mat2 mat2::operator/=(float n) { return *this = *this / n; }
mat2 mat2::operator+=(const mat2& m) { return *this = *this + m; }
mat2 mat2::operator-=(const mat2& m) { return *this = *this - m; }

mat2 operator*(float n, const mat2& m) { return m * n; }

std::ostream& operator<<(std::ostream& out, const mat2& m)
{
  size_t maxLengths[] = { 0, 0 };
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
    for (size_t j = values[i].length(); j < maxLengths[i % RANK] + 1; j++)
      out << ' ';

    if (i % RANK == RANK - 1)
    {
      if (i < ELEMENTS)
        out << "|\n";
      else
        out << "|";
    }
  }

  return out;
}