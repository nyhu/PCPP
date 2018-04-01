#ifndef __BULLET_LIST__
#define __BULLET_LIST__

#include <cstring>

#include "../ships/IShip.hpp"
#include "../enemy/EnemyList.hpp"
#include "../../settings/settings.hpp"

class BulletList
{
public:
  BulletList();
  ~BulletList();

  void pushBullet(AShip *s);
  void moveBullets();
  int collide(IShip &s);
  void computePlayfield(t_playfield &playfield);

private:
  AShip **bullets;
};

#endif