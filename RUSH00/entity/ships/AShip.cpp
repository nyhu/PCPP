#include "AShip.hpp"

AShip::AShip() : pv(100), ouput('0'), posX(0), posY(0), directionX(0), directionY(0), frameSinceLastAttack(0)
{
}

AShip::AShip(int pv, char ouput, int posX, int posY, int directionX, int directionY)
    : pv(pv), ouput(ouput), posX(posX), posY(posY), directionX(directionX), directionY(directionY), frameSinceLastAttack(0)
{
}

AShip::AShip(AShip const & src)
{
    *this = src;
}

AShip &AShip::operator=(const AShip &rhs)
{
    this->pv = rhs.pv;
    this->ouput = rhs.ouput;
    this->posX = rhs.posX;
    this->posY = rhs.posY;
    this->directionX = rhs.directionY;
    this->directionY = rhs.directionX;
    this->frameSinceLastAttack = rhs.frameSinceLastAttack;
    return (*this);
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
    if (this->touchBorder())
        respawn();
}

void AShip::stop()
{
    this->directionY = 0;
    this->directionX = 0;
}

void AShip::respawn()
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

// Always collide with a player ship or a player bullet
// return damage done for score incrementation
int AShip::collide(AShip &s)
{
    int s1dmg = this->pv;
    int s2dmg = s.pv;
    s.pv -= s1dmg;
    this->pv -= s2dmg;
    if (s.pv < 0)
        s.pv = 0;
    if (this->pv < 0)
        this->pv = 0;
    return s1dmg;
}

void AShip::setDirection(int x, int y)
{
    this->directionX = x;
    this->directionY = y;
}

void AShip::setPosition(int x, int y)
{
    this->posX = x;
    this->posY = y;
}

bool AShip::touchBorder()
{
    if (this->posX <= MIN_W || this->posY <= MIN_H)
        return true;
    if (this->posX >= MAX_W || this->posY >= MAX_H - 2)
        return true;
    return false;
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

int AShip::getPv()
{
    return this->pv;
}