#ifndef INSTANTKEY
#define INSTANTKEY

#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN64) || defined(_WIN32)
    #include <conio.h>
    #include <windows.h>
    char GetKeyInputWin() {
        while(!_kbhit()) { }
        return _getch();
    }
    #define GetKeyInput GetKeyInputWin();
#elif defined(__linux__)
    #include <termios.h>
    #include <unistd.h>

    struct termios orig_termios;

    void disable_raw_mode() {
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
    }

    void enable_raw_mode() {
        tcgetattr(STDIN_FILENO, &orig_termios);
        struct termios raw = orig_termios;
        raw.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
        raw.c_cc[VMIN] = 1;              // Wait for at least 1 byte
        raw.c_cc[VTIME] = 0;             // No timeout
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
        atexit(disable_raw_mode);
    }
    int GetKeyInputLin() {
        enable_raw_mode();
        int ch;
        while ((ch = getchar()) < 0) {}
        disable_raw_mode();
        return ch;
    }
    #define GetKeyInput GetKeyInputLin();
#endif

#endif

