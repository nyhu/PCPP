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
#define ENEMY_COLOR 4
#define P1_COLOR 5
#define P2_COLOR 6
class Display
{
  public:
    Display();
    Display(const Display &d);
    virtual ~Display();
    Display &operator=(const Display &d);//no sens but copliente ^^


    int menu(int nbPlayer);
    int render(t_playfield playfield, t_playfield bgPlayfield, t_playfield playfP1, t_playfield playfP2);
    void printHud(int pv, int lives, int score, int enemyNb,  clock_t t);
    void printHudP2(int pv, int lives, int score);
  private:
    int resizeHandler();
    void renderBorders(WINDOW *w, int color);
    void printBgPlayfield(t_playfield playfield);
    void printPlayfield(t_playfield playfield, int color);
    // std::stringstream hudInfosToStr(int pv, int lives, int score, int enemyNb);

    WINDOW *win;
    int maxH;
    int maxW;
    int mainWinH;
    int mainWinW;

    WINDOW *hud;
    WINDOW *hudP2;
};

#endif