#ifndef __DISPLAY__
#define __DISPLAY__

#include <sys/ioctl.h>
#include <curses.h>
#include <iostream>
#include <string>
#include "../settings/settings.hpp"

#define NORMAL_COLOR 1
#define BORDER_COLOR 2

class Display
{
  public:
    Display();
    Display(const Display &d);
    ~Display();

    Display &operator=(const Display &d);

    int render();
  private:
    int resizeHandler();
    void renderBorders();
    WINDOW *win;
    int maxH;
    int maxW;
    int mainWinH;
    int mainWinW;
};

#endif