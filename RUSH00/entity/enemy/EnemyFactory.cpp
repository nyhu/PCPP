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
    nbOfEnemy = 0;
    for (int i = 0; *this->flist > i; i++)
    {
        IShip &s = this->flist->getShip(i);

        if (s.getPosX() == p1.getPosX() && s.getPosY() == p1.getPosY())
            p1.score += s.collide(p1);
        if (p2 && s.getPosX() == p2->getPosX() && p2->getPosY() == p2->getPosY())
            p2->score += s.collide(*p2);

        bullets.collide(s); // enemy friendly fire
        p1.score += p1.bullets.collide(s);
        if (p2)
            p2->score += p2->bullets.collide(s);

        if (s.getPv() == 0)
            continue;

        p[s.getPosY()][s.getPosX()] = s.getOutput();
        nbOfEnemy++;
    }
    for (int i = 0; *this->elist > i; i++)
    {
        IShip &s = this->elist->getShip(i);

        if (s.getPosX() == p1.getPosX() && s.getPosY() == p1.getPosY())
            p1.score += s.collide(p1);
        if (p2 && s.getPosX() == p2->getPosX() && p2->getPosY() == p2->getPosY())
            p2->score += s.collide(*p2);

        bullets.collide(s); // enemy friendly fire
        p1.score += p1.bullets.collide(s);
        if (p2)
            p2->score += p2->bullets.collide(s);

        if (s.getPv() == 0)
            continue;

        p[s.getPosY()][s.getPosX()] = s.getOutput();
        nbOfEnemy++;
    }

    if (nbOfEnemy < 1)
    {
        this->flist->populateFighter(p1.score / 100 + p1.score % 7 + 5);
        this->elist->populateEnforcer(p1.score / 10000 + 1);
    }

    // Bullets are added last for better display
    bullets.computePlayfield(p);
    p1.bullets.computePlayfield(p);
    if (p2)
        p2->bullets.computePlayfield(p);
}

void EnemyFactory::attack()
{
    for (int i = 0; *this->flist > i; i++)
    {
        IShip &s = this->flist->getShip(i);
        if (s.getPv() == 0)
            continue;
        s.attack(bullets);
    }
    for (int i = 0; *this->elist > i; i++)
    {
        IShip &s = this->elist->getShip(i);
        if (s.getPv() == 0)
            continue;
        s.attack(bullets);
    }
}

int EnemyFactory::getEnemyNb()
{
    return nbOfEnemy - 1;
}