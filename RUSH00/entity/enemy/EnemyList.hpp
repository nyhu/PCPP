#ifndef __ENEMY_LIST__
#define __ENEMY_LIST__

#include "../ships/IShip.hpp"
#include "units/Fighter.hpp"

class EnemyList
{
  public:
    EnemyList();
    ~EnemyList();
    EnemyList(EnemyList const & src);
    EnemyList &operator=(EnemyList const &rhs);


    bool operator>(int nb);

    void populateFighter(int nb);

    IShip &getShip(int i);
    int   getNb();
    
  private:
    IShip *ships;
    int nb;
};

#endif