#include "Fighter.hpp"

Fighter::Fighter()
{
    this->pv = 10;

    srand(time(0));
    this->posX = rand() % PLAYGROUND_W;
    this->posY = rand() % 2;
    if (this->posY > 1)
        this->posY = MAX_H;
    else
        this->posY = MIN_H;

    this->directionX = ((rand() % 4) - 2);
    if (this->posY == MIN_H)
        this->directionY = 1;
    else
        this->directionY = -1;
}

Fighter::~Fighter()
{
}

Fighter::Fighter(Fighter const & src)
{
    *this = src;
}

Fighter &Fighter::operator=(const Fighter &rhs)
{
    this->pv = rhs.pv ;
    this->ouput = rhs.ouput;
    this->posX = rhs.posX;
    this->posY = rhs.posY;
    this->directionX = rhs.directionY;
    this->directionY = rhs.directionX;
    this->frameSinceLastAttack = rhs.frameSinceLastAttack;
    return (*this);
}


void Fighter::move()
{
    if ((this->directionX || this->directionY) && this->posX > 10 && this->posY > 10)
    {
        if (rand() % 6 > 4)
            stop();
    }
    if (!this->directionX && !this->directionY && (rand() % 42 > 40))
        restart();
    AShip::move();
}

void Fighter::attack(BulletList &b)
{
    if (frameSinceLastAttack > 12)
    {
        frameSinceLastAttack = 0;
        b.pushBullet(new AShip(1, '-', this->posX - 1, this->posY, -1, 0));
        return;
    }
    ++frameSinceLastAttack;
}

void Fighter::restart()
{
    if (rand() % 3 > 0)
     this->directionY = (rand() % 2 > 0) ?  -1 : 1;
    else
     this->directionX = (rand() % 2 > 0) ?  -1 : 1;
}

void Fighter::respawn()
{
    if (posX == MIN_W)
        posX = MAX_W;
    else if (posX == MAX_W)
        posX = MIN_W;
    if (posY == MIN_H)
        posY = MAX_H;
    else if (posY == MAX_H)
        posY = MIN_H;
 return ;
}