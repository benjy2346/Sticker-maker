#include "Image.h"

#include <iostream>

int main() {
  Image alma;

  std::cout << "Using Image::lighten to create `lighten.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  std::cout<< alma.getPixel(0,0)<<std::endl;
  alma.lighten(0.2);
  alma.writeToFile("../lighten.png");
  std::cout<< alma.getPixel(0,0)<<std::endl;

  std::cout << "Using Image::saturate to create `saturate.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.saturate(0.2);
  alma.writeToFile("../saturate.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(0.5);
  alma.writeToFile("../scale2x.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(900,900);
  alma.writeToFile("../scalesqurex.png");
 }
