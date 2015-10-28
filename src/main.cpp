#include <iostream>
#include <cstdlib>

#include "ImageWrite.h"

int main()
{
  ImageWrite my_image(400,400);
  my_image.clear(0,0,0);

  //diagonal
  my_image.drawLine(0,0,399,399);
  my_image.drawLine(399,0,0,399);

  //horzional
  my_image.drawLine(200,0,200,399);
  //vertical
  my_image.drawLine(0,200,399,200);

  my_image.drawLine(100,0,300,399);
  my_image.drawLine(300,0,100,399);
  my_image.drawLine(0,100,399,300);
  my_image.drawLine(0,300,399,100);

  /*for( int i=0; i<20; i++ )
  {
     my_image.drawLine(100,0,300,399);
  }*/


  my_image.save("test_t.ppm");
  std::cout<<"EXIT_SUCCESS\n";
  return EXIT_SUCCESS;
}
