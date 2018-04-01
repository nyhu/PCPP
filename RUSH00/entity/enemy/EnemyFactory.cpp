#include "EnemyFactory.hpp"

EnemyFactory::EnemyFactory() : score(0)
{
    this->elist = new EnemyList;
    this->elist->populateFighter(3);
    this->score++; // cause unused at the moment
}

EnemyFactory::~EnemyFactory()
{
}

void EnemyFactory::move()
{
    this->elist->move();
}

void EnemyFactory::computePlayfield(t_playfield &p) {
    for (int i = 0; *this->elist > i; i++) {
        IShip &s = this->elist->getShip(i);
        p[s.getPosY()][s.getPosX()] = s.getOutput();    
    }
}