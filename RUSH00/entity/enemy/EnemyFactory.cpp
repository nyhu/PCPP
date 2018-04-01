#include "EnemyFactory.hpp"

EnemyFactory::EnemyFactory()
{
    this->flist = new EnemyList;
    this->flist->populateFighter(5);

    this->elist = new EnemyList;
    this->mlist = new EnemyList;

    this->startTime = clock();
}

EnemyFactory::~EnemyFactory()
{
    delete this->flist;
    delete this->elist;
    delete this->mlist;
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
    elist->move();
    flist->move();
    mlist->move();
    bullets.moveBullets();
}

void EnemyFactory::collide(Player &p)
{
    bullets.collide(p);
}

void EnemyFactory::computePlayfield(t_playfield &p, Player &p1, Player *p2)
{
    this->nbOfEnemy = elist->computePlayfield(p, p1, p2, bullets);
    this->nbOfEnemy += flist->computePlayfield(p, p1, p2, bullets);
    this->nbOfEnemy += mlist->computePlayfield(p, p1, p2, bullets);

    clock_t now = clock();
    if (this->nbOfEnemy <= ((now - this->startTime ) / 100000000))
    {
        this->flist->populateFighter(p1.score / 100 + p1.score % 5 + 5);
        this->elist->populateEnforcer(p1.score / 250 + 1);
        this->elist->populateMegatrope(p1.score / 500);
    }

    // Bullets are added last for better display
    bullets.computePlayfield(p);
}

void EnemyFactory::attack()
{
    elist->attack(bullets);
    flist->attack(bullets);
    mlist->attack(bullets);
}

int EnemyFactory::getEnemyNb()
{
    clock_t now = clock();    
    return nbOfEnemy - ((now - this->startTime ) / 100000000);
}