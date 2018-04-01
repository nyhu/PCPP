#ifndef __BULLET_LIST__
#define __BULLET_LIST__

#include <map>
#include <ctime>
#include <iostream>
#include <sstream>

#include "../ships/IShip.hpp"
#include "../enemy/EnemyList.hpp"

class BulletList
{
public:
  BulletList();
  ~BulletList();

  void pushBullet(std::string origin, AShip *s);
  void pushBullet(std::string origin, int enemyIndex, AShip *s);
  void moveBullets();
  int collide(IShip &s);
  void computePlayfield(t_playfield &playfield);

private:
  std::map<std::string, AShip *> bullets;
};

#endif