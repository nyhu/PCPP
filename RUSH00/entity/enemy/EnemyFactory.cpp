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

void EnemyFactory::computePlayfield(t_playfield &p, IShip &p1, IShip *p2, BulletList &bList)
{
    nbOfEnemy = 0;
    for (int i = 0; *this->elist > i; i++)
    {
        IShip &s = this->elist->getShip(i);

        if (s.getPosX() == p1.getPosX() && s.getPosY() == p1.getPosY())
            this->score += s.collide(p1);
        if (p2 && s.getPosX() == p2->getPosX() && p2->getPosY() == p2->getPosY())
            this->score += s.collide(*p2);

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