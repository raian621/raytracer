#ifndef CANVAS_H
#define CANVAS_H

#include <stdint.h>
#include <stddef.h>

class Canvas
{
  public:
    Canvas(size_t, size_t);
    Canvas(const Canvas&);
    Canvas(Canvas&&);
    ~Canvas();

    Canvas& operator=(const Canvas&);
    Canvas& operator=(Canvas&&);
    uint32_t* operator[](int) const;

    size_t width() const;
    size_t height() const;

    void save_to_file(const char*, const char*);

  private:
    uint32_t** pixel_grid;
    size_t _width;
    size_t _height;
};

#endif