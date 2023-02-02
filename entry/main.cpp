#include "Image.h"
#include "StickerSheet.h"

using namespace cs225;
static void checkStickerPlacement(const Image& sticker, const Image& sheet, const int& xOffset, const int& yOffset) {
  for (size_t x = 0; x < sticker.width(); ++x) {
    for (size_t y = 0; y < sticker.height(); ++y) {
      const HSLAPixel &stickerPixel = sticker.getPixel(x, y);
      const HSLAPixel &sheetPixel = sheet.getPixel(x + xOffset, y + yOffset);
      // REQUIRE( (stickerPixel.a == 1 ? stickerPixel == sheetPixel : true) );
    }
  }
}
int main() {
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  //smaller
  Image alma;     alma.readFromFile("../shao.png");
  Image i;        i.readFromFile("../Victory Hand Emoji.png");
 // Image expected; expected.readFromFile("../tests/expected-3.png");

  StickerSheet sheet(alma, 100);
  i.scale(200,200);
  sheet.addSticker(i, 0, 500);
  sheet.addSticker(i, 600, 500);
sheet.addSticker(i, 300, 100);
  sheet.render().writeToFile("../myImage.png");
  return 0;
}
