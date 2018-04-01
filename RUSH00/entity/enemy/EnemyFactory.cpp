#include "EnemyFactory.hpp"

EnemyFactory::EnemyFactory()
{
    this->flist = new EnemyList;
    this->flist->populateFighter(5);

    this->elist = new EnemyList;
}

EnemyFactory::~EnemyFactory()
{
    delete this->flist;
    delete this->elist;
}

void EnemyFactory::move()
{
    elist->move();
    flist->move();
    bullets.moveBullets();
}

void EnemyFactory::collide(Player &p)
{
    bullets.collide(p);
}

void EnemyFactory::computePlayfield(t_playfield &p, Player &p1, Player *p2)
{
    nbOfEnemy = elist->computePlayfield(p, p1, p2, bullets);
    nbOfEnemy += flist->computePlayfield(p, p1, p2, bullets);

    if (nbOfEnemy < 1)
    {
        this->flist->populateFighter(p1.score / 100 + p1.score % 7 + 5);
        this->elist->populateEnforcer(p1.score / 10000 + 1);
    }

    // Bullets are added last for better display
    bullets.computePlayfield(p);
}

void EnemyFactory::attack()
{
    elist->attack(bullets);
    flist->attack(bullets);
}

int EnemyFactory::getEnemyNb()
{
    return nbOfEnemy - 1;
}