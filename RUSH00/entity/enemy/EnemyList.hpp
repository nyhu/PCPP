#ifndef __ENEMY_LIST__
#define __ENEMY_LIST__

#include "../ships/IShip.hpp"
#include "units/Fighter.hpp"
#include "units/Enforcer.hpp"

class EnemyList
{
  public:
    EnemyList();
    ~EnemyList();

    bool operator>(int nb);

    void populateFighter(int nb);
    void populateEnforcer(int nb);

    void move();

    IShip &getShip(int i);
    int   getNb();
    
  private:
    IShip *ships;
    int nb;
};

#endif