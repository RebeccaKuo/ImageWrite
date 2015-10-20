#ifndef IMAGEWRITE_H_
#define IMAGEWRITE_H_

#include <string>

class ImageWrite
{
  public:

  ImageWrite():m_width(0), m_height(0), m_data(0) {}
  ImageWrite(int _x, int _y);
  ~ImageWrite();

  void save(const std::string &_fname);
  void setPixel(int _x, int _y, unsigned char _r,
                unsigned char _g, unsigned char _b);
  void clear(unsigned char _r, unsigned char _g,
             unsigned char _b);

  private:

  int m_width;
  int m_height;
  unsigned char *m_data;

};

#endif
