#include "c_colours.h"
#include "grappos.h"
#include <iostream>

int main() {
  grappos::Create_WIN display;
  grappos::Clear();

  // make the smile
  grappos::GrapStart(5, 5, " ", display, c_colours::Background::Blue);
  grappos::GrapPlaceAscii(display, 0, 3, "#");
  grappos::GrapPlaceAscii(display, 1, 4, "#");
  grappos::GrapPlaceAscii(display, 2, 4, "#");
  grappos::GrapPlaceAscii(display, 3, 4, "#");
  grappos::GrapPlaceAscii(display, 4, 3, "#");

  // make the eyes
  grappos::GrapPlacePallete(display, 3, 1, c_colours::Foreground::Red);
  grappos::GrapPlaceAscii(display, 1, 1, "@");
  grappos::GrapPlaceAscii(display, 3, 1, "@");

  grappos::GrapPrint(display);

  std::cout << "wait...\n" << std::flush;
  grappos::WaitMs(2000);
  std::cout << "hello :3" << std::flush;

  return 0;
}
