#include "Megatrope.hpp"

Megatrope::Megatrope()
{
    this->ouput = '#';
    this->pv = 1000;

    srand(time(0));
    this->posX = MAX_W;
    this->posY = rand() % MAX_H;
    this->directionY = 0;
    this->directionX = -1;
}

Megatrope::~Megatrope()
{
}

void Megatrope::move()
{
    AShip::move();
}


void Megatrope::attack(BulletList &b)
{
    if (frameSinceLastAttack > 500)
    {
        frameSinceLastAttack = 0;
        b.pushBullet(new AShip(20, '#', this->posX - 1, this->posY, 0, 0));
        return;
    }
    ++frameSinceLastAttack;
}
