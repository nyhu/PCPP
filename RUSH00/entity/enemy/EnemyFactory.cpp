#include "EnemyFactory.hpp"

EnemyFactory::EnemyFactory() : score(0)
{
    this->elist = new EnemyList;
    this->elist->populateFighter(10);
}

EnemyFactory::~EnemyFactory()
{
}

void EnemyFactory::move()
{
    for (int i = 0; *this->elist > i; i++)
    {
        IShip &s = this->elist->getShip(i);
        s.move();
    }
}

void EnemyFactory::computePlayfield(t_playfield &p, IShip &player)
{
    bool listAlive = false;
    for (int i = 0; *this->elist > i; i++)
    {
        IShip &s = this->elist->getShip(i);
        if (s.getPosX() == player.getPosX() && s.getPosY() == player.getPosY())
            this->score += s.collide(player);
        if (s.getPv() == 0)
            continue;
        p[s.getPosY()][s.getPosX()] = s.getOutput();
        listAlive = true;
    }
    if (!listAlive)
        this->elist->populateFighter(10);
}

int EnemyFactory::getScore()
{
    return this->score;
}