#include "AShip.hpp"

AShip::AShip() : pv(100), ouput('0'), posX(0), posY(0), directionX(0), directionY(0)
{
}

AShip::~AShip()
{
}

void AShip::move()
{
    this->posX += this->directionX;
    this->posY += this->directionY;
    if (this->posX < 1)
        this->posX = 1;
    if (this->posX > (PLAYGROUND_W - 2))
        this->posX = PLAYGROUND_W - 2;
    if (this->posY < 1)
        this->posY = 1;
    if (this->posY > (PLAYGROUND_H - 2))
        this->posY = PLAYGROUND_H - 2;
}

void AShip::stop()
{
    this->directionY = 0;
    this->directionX = 0;
}

void AShip::setDirection(int x, int y)
{
    this->directionX = x;
    this->directionY = y;
}

int AShip::getPosX()
{
    return this->posX;
}

int AShip::getPosY()
{
    return this->posY;
}

char AShip::getOutput()
{
    return this->ouput;
}