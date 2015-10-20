#include <iostream>
#include <cstdlib>

#include "ImageWrite.h"

int main()
{
  std::cout<<"Working\n";
  ImageWrite my_image(400,400);
  for(int y=0; y<400; ++y)
  for(int x=0; x<400; ++x)
  {
    my_image.setPixel(x,y,rand()%255,rand()%125,rand()%255 );
  }

  //my_image.clear(255,0,0);
  my_image.save("test_rand2.ppm");

  //my_image.setPixel(500,50,255,255,255);

  std::cout<<"EXIT_SUCCESS\n";
  return EXIT_SUCCESS;

}
