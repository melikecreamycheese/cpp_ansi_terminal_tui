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

void GrapStart(int width, int lenght, std::string character, Create_WIN &window,
               std::string colour);
void GrapPrint(Create_WIN &window);
void GrapPlaceAscii(Create_WIN &window, int x, int y, std::string ascii);
void GrapPlacePallete(Create_WIN &window, int x, int y, std::string colour);
void Clear();
void WaitMs(int time);
} // namespace grappos

#endif
