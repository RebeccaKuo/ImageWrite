#include <iostream>
#include <cstdlib>

#include "ImageWrite.h"

int main()
{
  std::cout<<"Working\n";
  ImageWrite myImage(200,200);
  myImage.setPixel(500,50,255,255,255);
  return EXIT_SUCCESS;

}
