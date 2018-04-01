#include "EnemyFactory.hpp"

EnemyFactory::EnemyFactory() : score(0)
{
    this->elist = new EnemyList;
    this->elist->populateFighter(10);
}

EnemyFactory::~EnemyFactory()
{
    delete this->elist;
}

void EnemyFactory::move()
{
    for (int i = 0; *this->elist > i; i++)
    {
        IShip &s = this->elist->getShip(i);
        s.move();
    }
}

void EnemyFactory::computePlayfield(t_playfield &p, IShip &player, BulletList &bList)
{
    nbOfEnemy = 0;
    for (int i = 0; *this->elist > i; i++)
    {
        IShip &s = this->elist->getShip(i);
        if (s.getPosX() == player.getPosX() && s.getPosY() == player.getPosY())
            this->score += s.collide(player);
        this->score += bList.collide(s);
        if (s.getPv() == 0)
            continue;
        p[s.getPosY()][s.getPosX()] = s.getOutput();
        nbOfEnemy++;
    }
    if (!nbOfEnemy)
        this->elist->populateFighter(this->score / 10);
}

void EnemyFactory::attack(BulletList &bList)
{
    for (int i = 0; *this->elist > i; i++)
    {
        IShip &s = this->elist->getShip(i);
        if (s.getPv() == 0)
            continue;
        bList.pushBullet(s.attack());
    }   
}

int EnemyFactory::getScore()
{
    return this->score;
}

int EnemyFactory::getEnemyNb()
{
    return nbOfEnemy;
}