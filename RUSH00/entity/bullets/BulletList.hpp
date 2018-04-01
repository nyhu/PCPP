#ifndef __BULLET_LIST__
#define __BULLET_LIST__

#include <cstring>

#include "../ships/AShip.hpp"

class BulletList
{
public:
  BulletList();
  virtual ~BulletList();
  BulletList(BulletList const & src);
  BulletList &operator=(const BulletList &rhs);

  void pushBullet(AShip *s);
  void moveBullets();
  int collide(AShip &s);
  void computePlayfield(t_playfield &playfield);

private:
  AShip **bullets;
};

#endif