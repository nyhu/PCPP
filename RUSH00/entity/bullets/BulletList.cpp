#include "BulletList.hpp"

BulletList::BulletList()
{
    this->bullets = new AShip*[BULLETS_MAX_NUMBER + 1];
    for (int i = 0; i < BULLETS_MAX_NUMBER; i++)
        this->bullets[i] = NULL;
}

BulletList::~BulletList()
{
    for (int i = 0; i < BULLETS_MAX_NUMBER; i++)
    {
        if (!this->bullets[i])
            continue;
        delete this->bullets[i];
        this->bullets[i] = NULL;
    }
    delete this->bullets;
}

void BulletList::pushBullet(AShip *b)
{
    if (b == NULL)
        return;
    for (int i = 0; i < BULLETS_MAX_NUMBER; i++)
    {
        if (!this->bullets[i])
        {
            this->bullets[i] = b;
            return;
        }
        if (this->bullets[i]->touchBorder())
        {
            delete this->bullets[i];
            this->bullets[i] = b;
            return;
        }
    }
    delete b;
}

void BulletList::moveBullets()
{
    for (int i = 0; i < BULLETS_MAX_NUMBER; i++)
    {
        if (!this->bullets[i])
            continue;
        if (this->bullets[i]->touchBorder())
        {
            delete this->bullets[i];
            this->bullets[i] = NULL;
            continue;
        }
        this->bullets[i]->move();
    }
}

int BulletList::collide(IShip &s)
{
    for (int i = 0; i < BULLETS_MAX_NUMBER; i++)
        if (this->bullets[i] && this->bullets[i]->getPosX() == s.getPosX() && this->bullets[i]->getPosY() == s.getPosY())
        {
            if (this->bullets[i]->getPv() == 0)
            {
                delete this->bullets[i];
                this->bullets[i] = NULL;
                return 0;
            }
            return s.collide(*this->bullets[i]);
        }
    return 0;
}

void BulletList::computePlayfield(t_playfield &playfield)
{
    for (int i = 0; i < BULLETS_MAX_NUMBER; i++)
        if (this->bullets[i])
            playfield[this->bullets[i]->getPosY()][this->bullets[i]->getPosX()] = this->bullets[i]->getOutput();
}