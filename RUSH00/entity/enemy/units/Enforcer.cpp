#include "Enforcer.hpp"

Enforcer::Enforcer()
{
    this->pv = 40;
    this->ouput = '@';

    srand(time(0));
    this->posX = MAX_W - 2;
    this->posY = rand() % MAX_H;
    this->directionX = -(rand() % 4);
}

Enforcer::~Enforcer()
{
}

Enforcer::Enforcer(Enforcer const & src)
{
    *this = src;
}

Enforcer &Enforcer::operator=(const Enforcer &rhs)
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


void Enforcer::move()
{
    if ((this->directionX || this->directionY) && (rand() % 42 > 40))
        stop();
    if (!this->directionX && !this->directionY && (rand() % 6 > 4))
        restart();
    AShip::move();
}

void Enforcer::attack(BulletList &b)
{
    if (frameSinceLastAttack > 15)
    {
        frameSinceLastAttack = 0;
        b.pushBullet(new AShip(10, '*', this->posX - 1, this->posY, -1, 1));
        b.pushBullet(new AShip(10, '*', this->posX - 1, this->posY, -1, 0));
        b.pushBullet(new AShip(10, '*', this->posX - 1, this->posY, -1, -1));
        return;
    }
    ++frameSinceLastAttack;
}

void Enforcer::restart()
{
    if (rand() % 3 > 0)
        this->directionY = (rand() % 2 > 0) ? -1 : 1;
    else
        this->directionX = (rand() % 2 > 0) ? -1 : 1;
}