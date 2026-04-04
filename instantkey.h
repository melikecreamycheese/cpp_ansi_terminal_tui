#ifndef INSTANTKEY
#define INSTANTKEY

#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN64) || defined(_WIN32)
    #include <windows.h>

    char GetKeyInputWin() {
        for (int key =0; key < 256; key++) {
            if (GetAsyncKeyState(key) & 0x8000) {
                return key;
            }
        }
        return -1;
    }
    #define GetKeyInput GetKeyInputWin();
#elif defined(__linux__)
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
    struct termios oldt;

    void enableRawMode()
    {
        termios newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;

        newt.c_lflag &= ~(ICANON | ECHO); // no buffering, no echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        // make stdin non-blocking
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    }

    void disableRawMode()
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
    int GetKeyInputLin() {
        enableRawMode();
        unsigned char ch;
        if (read(STDIN_FILENO, &ch, 1) == 1)
            return ch; // return ASCII key
        disableRawMode();
        return -1; // no key pressed
        
    }
    #define GetKeyInput GetKeyInputLin();
#endif

#endif

