#include "canvas.h"

Canvas::Canvas(size_t width, size_t height)
  : _width(width), _height(height)
{
  pixel_grid = new uint32_t*[_width];
  for (int i = 0; i < _width; i++)
    pixel_grid[i] = new uint32_t[_height];
}

Canvas::Canvas(const Canvas& rhs)
  : Canvas(rhs._width, rhs._height)
{
  for (int x = 0; x < _width; x++)
    for (int y = 0; y < _height; y++)
      pixel_grid[x][y] = rhs[x][y];
}

Canvas::Canvas(Canvas&& rhs)
  : _width(rhs._width), _height(rhs._height), pixel_grid(rhs.pixel_grid)
{
  rhs._width = 0;
  rhs._height = 0;
  rhs.pixel_grid = NULL;
}

Canvas::~Canvas()
{
  for (int i = 0; i < _height; i++)
    delete pixel_grid[i];
  delete[] pixel_grid;
}

Canvas& Canvas::operator=(const Canvas& rhs)
{
  Canvas copy = rhs;
  std::swap(*this, copy);
  return *this;
}

Canvas& Canvas::operator=(Canvas&& rhs)
{
  std::swap(_width, rhs._width);
  std::swap(_height, rhs._height);
  std::swap(pixel_grid, rhs.pixel_grid);

  return *this;
}

uint32_t* Canvas::operator[](int col) const
{
  return pixel_grid[col];
}

size_t Canvas::width() const { return _width; }
size_t Canvas::height() const { return _height; }

void Canvas::save_to_file(const char* path)
{
  // TODO  
}