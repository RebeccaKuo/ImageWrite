#include "ImageWrite.h"
#include <iostream>
#include <cassert>
#include <fstream>

ImageWrite::ImageWrite(int _w, int _h)
{
  m_width = _w;
  m_height = _h;
  m_data = new unsigned char[m_width*m_height*3];
}


ImageWrite::~ImageWrite()
{
  if(m_data != 0)
  {
    delete [] m_data;
  }
}

void ImageWrite::save(const std::string &_fname)
{
  std::ofstream output;
  output.open(_fname);
  if( !output.is_open() )
  {
    std::cerr<<"Problem opening file "<<_fname<<std::endl;
    exit(EXIT_FAILURE);
  }

  //write header
  output<<"P3\n";
  output<<m_width<<" "<<m_height<<"\n";
  output<<"255\n";

  unsigned int index = -1;
  for( int x=0; x<m_width*m_height*3; ++x )
  {
    output<<(int)m_data[++index]<<" ";
  }
  output<<"\n";

  //remember to close
  output.close();
}

void ImageWrite::setPixel(int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b)
{
  assert(_x<m_width && _y<m_height);
  unsigned int index=(_y*m_width*3) + (_x*3);
  m_data[index]=_r;
  m_data[index+1]=_g;
  m_data[index+2]=_b;
}

void ImageWrite::clear(unsigned char _r, unsigned char _g,
                       unsigned char _b)
{
  for(int y=0; y<m_height; ++y)
  {
    for(int x=0; x<m_width; ++x)
    {
      setPixel(x,y,_r,_g,_b);
    }
  }
}
