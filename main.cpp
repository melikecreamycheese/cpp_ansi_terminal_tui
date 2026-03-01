#include "c_colours.h"
#include "grappos.h"

int main() {
  grappos::Create_WIN display;
  grappos::GrapStart(5, 5, " ", display, c_colours::Background::Blue);
  grappos::GrapPlaceAscii(display, 0, 3, "#");
  grappos::GrapPlaceAscii(display, 1, 4, "#");
  grappos::GrapPlaceAscii(display, 2, 4, "#");
  grappos::GrapPlaceAscii(display, 3, 4, "#");
  grappos::GrapPlaceAscii(display, 4, 3, "#");

  grappos::GrapPlacePallete(display, 3, 1, c_colours::Foreground::Red);
  grappos::GrapPlaceAscii(display, 1, 1, "@");
  grappos::GrapPlaceAscii(display, 3, 1, "@");

  grappos::GrapPrint(display);

  return 0;
}
