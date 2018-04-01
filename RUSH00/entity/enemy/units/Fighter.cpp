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
    if ((this->directionX || this->directionY) && this->posX > 10 && this->posY > 10) {
        int sixDice = rand() % 6;
        if (sixDice > 4)
            stop();
    }
    AShip::move();
}

AShip *Fighter::attack()
{
    return NULL;
}