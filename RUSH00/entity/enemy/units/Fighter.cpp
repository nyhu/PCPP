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

AShip *Fighter::attack()
{
    if (frameSinceLastAttack > 12)
    {
        frameSinceLastAttack = 0;
        return new AShip(1, '-', this->posX - 1, this->posY, -1, 0);
    }
    ++frameSinceLastAttack;
    return NULL;
}

void Fighter::restart()
{
    if (rand() % 3 > 0)
     this->directionY = (rand() % 2 > 0) ?  -1 : 1;
    else
     this->directionX = (rand() % 2 > 0) ?  -1 : 1;
}