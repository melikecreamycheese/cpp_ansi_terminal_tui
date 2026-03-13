#include "grappos.h"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

namespace grappos {

void GrapStart(int width, int lenght, std::string character,
               grappos::Create_WIN &window, std::string colour) {
  window.WIDTH = width;
  window.LENGHT = lenght;
  for (int i = 0; i < lenght; i++) {
    for (int k = 0; k < width; k++) {
      window.WINDOW.push_back(character);
      window.PALLETE.push_back(colour);
    }
    window.WINDOW.push_back("\n");
    window.PALLETE.push_back("\033[0m");
  }
}

void GrapPrint(grappos::Create_WIN &window) {
  for (int i = 0; i != window.WINDOW.size(); i++) {
    std::cout << window.PALLETE[i] << std::flush;
    std::cout << window.WINDOW[i] << std::flush;
    std::cout << "\033[0m" << std::flush;
  }
  std::cout << std::endl;
}

void GrapPlaceAscii(Create_WIN &window, int x, int y, std::string ascii) {
  window.WINDOW[x + y * (window.WIDTH + 1)] = ascii;
}

void GrapPlacePallete(Create_WIN &window, int x, int y, std::string colour) {
  window.PALLETE[x + y * (window.WIDTH + 1)] = colour;
}

void Clear() { std::cout << "\x1B[2J\x1B[H" << std::flush; }

void WaitMs(int time) {
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void HoLine(Create_WIN &window, int x, int y, int h, std::string ascii) {
  for (int i = 0; i < h; i++) {
    GrapPlaceAscii(window, x + i, y, ascii);
  }
}

void VeLine(Create_WIN &window, int x, int y, int v, std::string ascii) {
  for (int i = 0; i < v; i++) {
    GrapPlaceAscii(window, x, y + i, ascii);
  }
}

} // namespace grappos
