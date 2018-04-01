#ifndef __GAME__
#define __GAME__

#include <curses.h>
#include <iostream>
#include <signal.h>
#include <cstring>
#include <time.h>

#include "../settings/settings.hpp"
#include "../display/Display.hpp"
#include "../entity/player/Player.hpp"
#include "../entity/enemy/EnemyFactory.hpp"

class Game
{
public:
  Game();
  Game(const Game &g);
  ~Game();

  Game &operator=(const Game &g);

  void play();

private:
  void takeInputUntilNextFrame(clock_t x_startTime);
  void computePlayfield();
  void computeMoves();

  Display display;
  t_playfield playfield;
  Player p1;
  EnemyFactory eFactory;
};

#endif
