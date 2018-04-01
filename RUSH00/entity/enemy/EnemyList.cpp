#include "EnemyList.hpp"

EnemyList::EnemyList()
{
    // this->ships = nullptr;
    this->ships = NULL;
}

EnemyList::~EnemyList()
{
    if (this->ships)
        delete[] this->ships;
}
EnemyList::EnemyList(EnemyList const & src)
{
    *this = src;   
}
EnemyList &EnemyList::operator=(EnemyList const &rhs)
{
    this->ships = rhs.ships;
    this->nb = rhs.nb;
    return (*this);

}


bool EnemyList::operator>(int nb)
{
    return this->nb > nb;
}

void EnemyList::populateFighter(int nb)
{
    if (nb <= 0)
        return;
    if (this->ships)
        delete[] this->ships;
    this->ships = new Fighter[nb];
    this->nb = nb;
    if (nb == 1)
        return;
    int x = this->ships[0].getPosX();
    int y = this->ships[0].getPosY();
    int absciceModif = 0;
    if (x > (PLAYGROUND_W / 2))
        absciceModif -= 2;
    else
        absciceModif += 2;
    for (int i = 0; *this > i; i++)
    {
        this->ships[i].setPosition(x + (absciceModif * i), y);
    }
}

IShip &EnemyList::getShip(int i)
{
    return this->ships[i];
}

int EnemyList::getNb()
{
    return nb;
}