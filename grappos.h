#ifndef GRAPPOS
#define GRAPPOS

#include <string>
#include <vector>

namespace grappos {

struct Create_WIN {
  std::vector<std::string> WINDOW;
  std::vector<std::string> PALLETE;
  int WIDTH;
  int LENGHT;
};

struct Vec2 {
  int x;
  int y;
};

void GrapStart(int width, int lenght, std::string character, Create_WIN &window,
               std::string colour);
void GrapPrint(Create_WIN &window);
void GrapPlaceAscii(Create_WIN &window, int x, int y, std::string ascii);
void GrapPlacePallete(Create_WIN &window, int x, int y, std::string colour);
void Clear();
void WaitMs(int time);

void HoLine(Create_WIN &window, Vec2 pos, int h, std::string ascii);
void VeLine(Create_WIN &window, Vec2 pos, int v, std::string ascii);
} // namespace grappos

#endif
