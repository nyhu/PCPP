#include "BulletList.hpp"

BulletList::BulletList()
{
}

BulletList::~BulletList()
{
    for (std::map<std::string, AShip *>::iterator it = this->bullets.begin(); it != this->bullets.end(); ++it)
    {
        AShip *b = it->second;
        this->bullets.erase(it);
        delete b;
    }
}

void BulletList::pushBullet(std::string origin, AShip *b)
{
    if (b == NULL)
        return;
    std::time_t t = std::time(0);
    std::ostringstream s;
    s << origin << t;
    if (this->bullets.count(s.str()) > 0)
    {
        delete b;
        return;
    }
    this->bullets.insert(std::make_pair(s.str(), b));
}

void BulletList::moveBullets()
{
    for (std::map<std::string, AShip *>::iterator it = this->bullets.begin(); it != this->bullets.end(); ++it)
        it->second->move();
}

int BulletList::collide(IShip &s)
{
    for (std::map<std::string, AShip *>::iterator it = this->bullets.begin(); it != this->bullets.end(); ++it)
        if (it->second->getPosX() == s.getPosX() && it->second->getPosY() == s.getPosY())
        {
            if (it->second->getPv() == 0)
            {
                delete it->second;
                this->bullets.erase(it);
            }
            return s.collide(*it->second);
        }
    return 0;
}

void BulletList::computePlayfield(t_playfield &playfield)
{
    for (std::map<std::string, AShip *>::iterator it = this->bullets.begin(); it != this->bullets.end(); ++it)
        playfield[it->second->getPosY()][it->second->getPosX()] = it->second->getOutput();
}