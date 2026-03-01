#ifndef C_COLOURS
#define C_COLOURS
#include <string>

namespace c_colours {
namespace Foreground {
std::string Black = "\033[30m";
std::string Red = "\033[31m";
std::string Green = "\033[32m";
std::string Yellow = "\033[33m";
std::string Blue = "\033[34m";
std::string Magenta = "\033[35m";
std::string Cyan = "\033[36m";
std::string White = "\033[37m";
std::string Reset = "\033[0m";
} // namespace Foreground

namespace Background {
std::string Black = "\033[40m";
std::string Red = "\033[41m";
std::string Green = "\033[42m";
std::string Yellow = "\033[43m";
std::string Blue = "\033[44m";
std::string Magenta = "\033[45m";
std::string Cyan = "\033[46m";
std::string White = "\033[47m";
std::string Reset = "\033[0m";
} // namespace Background

namespace Bright_Foreground {
std::string Black = "\033[90m";
std::string Red = "\033[91m";
std::string Green = "\033[92m";
std::string Yellow = "\033[93m";
std::string Blue = "\033[94m";
std::string Magenta = "\033[95m";
std::string Cyan = "\033[96m";
std::string White = "\033[97m";
std::string Reset = "\033[0m";
} // namespace Bright_Foreground

namespace Bright_Background {
std::string Black = "\033[100m";
std::string Red = "\033[101m";
std::string Green = "\033[102m";
std::string Yellow = "\033[103m";
std::string Blue = "\033[104m";
std::string Magenta = "\033[105m";
std::string Cyan = "\033[106m";
std::string White = "\033[107m";
std::string Reset = "\033[0m";
} // namespace Bright_Background

std::string ClearScreen = "\033[2J\033[1;1H";
} // namespace c_colours

#endif
