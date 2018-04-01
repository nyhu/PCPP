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
    virtual ~EnemyFactory();
    EnemyFactory(EnemyFactory const & src);
    EnemyFactory &operator=(const EnemyFactory &rhs);    

    void move();
    void computePlayfield(t_playfield &p, Player &p1, Player *p2);
    void attack();
    void collide(Player &p);

    int getEnemyNb();
    clock_t getTime();

  private:
    clock_t startTime;

    EnemyList *flist;
    EnemyList *elist;
//    EnemyList *mlist;

    BulletList bullets;
    int nbOfEnemy;
};

#endif