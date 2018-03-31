#ifndef __GAME__
#define __GAME__

#include <iostream>
#include <signal.h>
#include "../display/Display.hpp"

class Game
{
public:
  Game();
  Game(const Game &g);
  ~Game();

  Game &operator=(const Game &g);

  void play();

private:
  void annonce();

  Display *display;
};

#endif