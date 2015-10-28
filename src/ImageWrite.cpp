#include "ImageWrite.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <math.h>

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

void ImageWrite::drawLine( const int _x1, const int _y1,
                           const int _x2, const int _y2 )
{
  int x(0), y(0);
  int delta_x = _x2 - _x1;
  int delta_y = _y2 - _y1;
  double delta_err = (double)delta_y/(double)delta_x;

  if(_x1 == _x2) //horzional line
  {
    int index_y = fmin(_y1, _y2);
    for( y = index_y; y<abs(delta_y); y++ )
    {
       setPixel(_x1, y, 255,255,255);
       //std::cout<<_x1<<" "<<y<<std::endl;
    }
  }
  else if( _x2 > _x1 )
  {
      for( x=_x1; x<_x1+abs(delta_x); x++ )
      {
        y = delta_err*(double)(x - _x1)+_y1;
        setPixel(x, y, 255,255,255);
        //std::cout<<x<<" "<<y<<" "<<delta_err<<std::endl;
      }
  }
  else
  {
    for( x=_x2; x<_x2+abs(delta_x); x++ )
    {
      y = delta_err*(double)(x - _x2)+_y2;
      setPixel(x, y, 255,255,255);
      //std::cout<<x<<" "<<y<<" "<<delta_err<<std::endl;
    }
  }

  setPixel(_x1, _y1, 255,0,0); //origin: red dot
  setPixel(_x2, _y2, 0,255,0); //end   : green dot
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
