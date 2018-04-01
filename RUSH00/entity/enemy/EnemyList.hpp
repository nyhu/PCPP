#ifndef __ENEMY_LIST__
#define __ENEMY_LIST__

#include "../ships/IShip.hpp"
#include "units/Fighter.hpp"

class EnemyList
{
  public:
    EnemyList();
    ~EnemyList();

    bool operator>(int nb);

    void populateFighter(int nb);

    IShip &getShip(int i);
    
  private:
    IShip *ships;
    int nb;
};

#endif