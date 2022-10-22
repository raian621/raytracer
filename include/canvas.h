#ifndef CANVAS_H
#define CANVAS_H

#include <stdint.h>
#include <stddef.h>

class Canvas
{
  private:
    size_t _width;
    size_t _height;
    uint32_t** pixel_grid;

  public:
    Canvas(size_t width = 0, size_t height = 0);
    Canvas(const Canvas&);
    Canvas(Canvas&&);
    ~Canvas();

    Canvas& operator=(const Canvas&);
    Canvas& operator=(Canvas&&);
    uint32_t* operator[](int) const;

    size_t width() const;
    size_t height() const;

    void save_to_file(const char*, const char*) const;
};

#endif