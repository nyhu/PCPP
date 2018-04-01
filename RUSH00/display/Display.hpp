#ifndef __DISPLAY__
#define __DISPLAY__

#include <sys/ioctl.h>
#include <curses.h>
#include <iostream>
#include <iomanip> 
#include <sstream>
#include <string>
#include "../settings/settings.hpp"

#define NORMAL_COLOR 1
#define BORDER_COLOR 2
#define BACKGROUND_COLOR 3
class Display
{
  public:
    Display();
    Display(const Display &d);
    ~Display();

    Display &operator=(const Display &d);

    int render(t_playfield playfield, t_playfield bgPlayfield);
    void printHud(int pv, int lives, int score, int enemyNb);
  private:
    int resizeHandler();
    void renderBorders();
    void printBgPlayfield(t_playfield playfield);
    void printPlayfield(t_playfield playfield);

    WINDOW *win;
    int maxH;
    int maxW;
    int mainWinH;
    int mainWinW;

    WINDOW *hud;
};

#endif