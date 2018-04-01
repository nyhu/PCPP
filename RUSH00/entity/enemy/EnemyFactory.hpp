#ifndef __ENEMY_FACTORY__
#define __ENEMY_FACTORY__

#include "../ships/IShip.hpp"
#include "EnemyList.hpp"

class EnemyFactory {
    public:
    EnemyFactory();
    ~EnemyFactory();

    void move();
    void computePlayfield(t_playfield &p, IShip &player);
    
    private:
    EnemyList *elist;
    int score;
};

#endif