#ifndef __ENFORCER__
#define __ENFORCER__

#include "../../ships/IShip.hpp"

class Enforcer : public IShip
{
  public:
    Enforcer();
    ~Enforcer();

    void move();
    void restart();
    void attack(BulletList &b);
};

#endif