#ifndef __DISPLAY__
#define __DISPLAY__

#include <sys/ioctl.h>
#include <curses.h>
#include <iostream>
#include <string>
#include "../settings/settings.hpp"

#define NORMAL_COLOR 1
#define BORDER_COLOR 2

typedef char t_playfield[PLAYGROUND_H][PLAYGROUND_W] ;

class Display
{
  public:
    Display();
    Display(const Display &d);
    ~Display();

    Display &operator=(const Display &d);

    int render(t_playfield playfield);
  private:
    int resizeHandler();
    void renderBorders();
    void printPlayfield(t_playfield playfield);

    WINDOW *win;
    int maxH;
    int maxW;
    int mainWinH;
    int mainWinW;
};

#endif