#include "c_colours.h"
#include "grappos.h"
#include "instantkey.h"
#include <iostream>

int main() {
  grappos::Create_WIN display;
  grappos::Clear();
  grappos::GrapStart(20, 10, " ", display, c_colours::Background::Black);
  int x =1;
  int y =1;
  int key;

  while (key != 27){
    key = GetKeyInput;
    switch (key)
    {
    case 'a':
      x -= 1;
      break;
    case 'd':
      x += 1;
      break;
    case 'w':
      y -= 1;
      break;
    case 's':
      y += 1;
      break;
    }
    grappos::FillWin(" ", display);
    grappos::GrapPlaceAscii(display, x, y, "#");
    grappos::Clear();
    grappos::GrapPrint(display);
  }


  

  return 0;
}
