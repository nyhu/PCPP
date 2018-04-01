#include "EnemyList.hpp"

EnemyList::EnemyList()
{
    this->ships = NULL;
    this->nb = 0;
}

EnemyList::~EnemyList()
{
    if (this->ships)
        delete[] this->ships;
}
EnemyList::EnemyList(EnemyList const &src)
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
    this->nb = nb;
    this->ships = new Fighter[nb];
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
        this->ships[i].setPosition(x + (absciceModif * i), y);
}

void EnemyList::populateEnforcer(int nb)
{
    if (nb <= 0)
        return;
    if (this->ships)
        delete[] this->ships;
    this->nb = nb;
    this->ships = new Enforcer[nb];
    if (nb == 1)
        return;
    int x = this->ships[0].getPosX();
    int y = this->ships[0].getPosY();
    int absciceModif = 0;
    if (y > (PLAYGROUND_H / 2))
        absciceModif -= 4;
    else
        absciceModif += 4;
    for (int i = 0; *this > i; i++)
        this->ships[i].setPosition(x, y + (absciceModif * i));
}

void EnemyList::populateMegatrope(int nb)
{
    if (nb <= 0)
        return;
    if (this->ships)
        delete[] this->ships;
    this->nb = nb;
    this->ships = new Megatrope[nb];
    int x = this->ships[0].getPosX();
    int y = this->ships[0].getPosY();
    this->ships[0].setPosition(x - 1, y - 1);
    for (int i = 1; *this > i; i++)
        this->ships[i].setPosition(x, y - 1);
}

void EnemyList::move()
{
    for (int i = 0; *this > i; i++)
        if (this->ships[i].getPv() != 0)
            ships[i].move();
}

void EnemyList::attack(BulletList &b)
{
    for (int i = 0; *this > i; i++)
        if (ships[i].getPv() != 0)
            ships[i].attack(b);
}

int EnemyList::computePlayfield(t_playfield &p, Player &p1, Player *p2, BulletList &b)
{
    int nbOfEnemy = 0;
    for (int i = 0; *this > i; i++)
        if (ships[i].getPv() != 0)
        {
            IShip &s = ships[i];
            if (s.getPosX() == p1.getPosX() && s.getPosY() == p1.getPosY())
                p1.score += s.collide(p1);
            if (p2 && s.getPosX() == p2->getPosX() && s.getPosY() == p2->getPosY())
                p2->score += s.collide(*p2);

            b.collide(s); // enemy friendly fire
            p1.score += p1.bullets.collide(s);
            if (p2)
                p2->score += p2->bullets.collide(s);

            if (s.getPv() == 0)
                continue;

            p[s.getPosY()][s.getPosX()] = s.getOutput();
            nbOfEnemy++;
        }
    return nbOfEnemy;
}

IShip &EnemyList::getShip(int i)
{
    return this->ships[i];
}

int EnemyList::getNb()
{
    return nb;
}