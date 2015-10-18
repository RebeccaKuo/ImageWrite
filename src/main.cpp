#include <iostream>
#include <cstdlib>

#include "ImageWrite.h"

int main()
{
  std::cout<<"Working\n";
  ImageWrite my_image(200,200);
  my_image.setPixel(500,50,255,255,255);
  return EXIT_SUCCESS;

}
