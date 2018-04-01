#include "EnemyList.hpp"

EnemyList::EnemyList()
{
    this->ships = nullptr;
}

EnemyList::~EnemyList()
{
    if (this->ships)
        delete[] this->ships;
}

bool EnemyList::operator>(int nb)
{
    return this->nb > nb;
}

void EnemyList::populateFighter(int nb)
{
    if (this->ships)
        delete[] this->ships;
    this->ships = new Fighter[nb];
    this->nb = nb;
}

void EnemyList::move()
{
    if (this->ships)
        for (int i = 0; i < this->nb; i++)
        {
            this->ships[i].move();
        }
}

IShip &EnemyList::getShip(int i)
{
    return this->ships[i];
}