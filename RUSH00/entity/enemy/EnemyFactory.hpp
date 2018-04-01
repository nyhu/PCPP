#ifndef __ENEMY_FACTORY__
#define __ENEMY_FACTORY__

#include "../ships/IShip.hpp"
#include "../player/Player.hpp"
#include "../bullets/BulletList.hpp"
#include "EnemyList.hpp"

class EnemyFactory
{
  public:
    EnemyFactory();
    ~EnemyFactory();

    void move();
    void computePlayfield(t_playfield &p, Player &p1, Player *p2);
    void attack();
    void collide(Player &p);

    int getEnemyNb();

  private:
    EnemyList *elist;
    int nbOfEnemy;
    BulletList bullets;
};

#endif