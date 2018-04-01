#include "EnemyFactory.hpp"

EnemyFactory::EnemyFactory() : score(0)
{
    this->elist = new EnemyList;
    this->elist->populateFighter(10);
    this->score++; // cause unused at the moment
}

EnemyFactory::~EnemyFactory()
{
}

void EnemyFactory::move()
{
    for (int i = 0; *this->elist > i; i++) {
        IShip &s = this->elist->getShip(i);
        s.move();
    }
}

void EnemyFactory::computePlayfield(t_playfield &p, IShip &player) {
    for (int i = 0; *this->elist > i; i++) {
        IShip &s = this->elist->getShip(i);
        if (s.getPosX() == player.getPosX() && s.getPosY() == player.getPosY())
            s.collide(player);
        p[s.getPosY()][s.getPosX()] = s.getOutput();    
    }
}