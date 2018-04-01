#ifndef __ENEMY_FACTORY__
#define __ENEMY_FACTORY__

#include "../ships/IShip.hpp"
#include "../bullets/BulletList.hpp"
#include "EnemyList.hpp"

class EnemyFactory {
    public:
    EnemyFactory();
    ~EnemyFactory();

    void move();
    void computePlayfield(t_playfield &p, IShip &p1, IShip *p2, BulletList& bList);
    void attack(BulletList &bList);

    int getScore();
    int getEnemyNb();
    
    private:
    EnemyList *elist;
    int score;
    int nbOfEnemy;
};

#endif