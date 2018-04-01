#include "EnemyFactory.hpp"

EnemyFactory::EnemyFactory()
{
    this->elist = new EnemyList;
    this->elist->populateFighter(5);
}

EnemyFactory::~EnemyFactory()
{
    delete this->elist;
}

EnemyFactory::EnemyFactory(EnemyFactory const & src)
{
    *this = src;
}

EnemyFactory &EnemyFactory::operator=(const EnemyFactory &rhs)
{
    this->elist = rhs.elist;
    this->nbOfEnemy = rhs.nbOfEnemy;
    this->bullets = rhs.bullets;
    return (*this);
}


void EnemyFactory::move()
{
    for (int i = 0; *this->elist > i; i++)
    {
        IShip &s = this->elist->getShip(i);
        s.move();
    }
    bullets.moveBullets();
}

void EnemyFactory::collide(Player &p)
{
    bullets.collide(p);
}

void EnemyFactory::computePlayfield(t_playfield &p, Player &p1, Player *p2)
{
    nbOfEnemy = 0;
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
    if (!nbOfEnemy)
        this->elist->populateFighter(p1.score / 20 + p1.score % 7 + 5);
    
    // Bullets are added last for better display
    bullets.computePlayfield(p);
    p1.bullets.computePlayfield(p);
    if (p2)
        p2->bullets.computePlayfield(p);
}

void EnemyFactory::attack()
{
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
    return nbOfEnemy;
}