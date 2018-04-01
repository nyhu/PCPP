#ifndef __ENFORCER__
#define __ENFORCER__

#include "../../ships/IShip.hpp"
#include "../../bullets/BulletList.hpp"

class Enforcer : public IShip
{
  public:
    Enforcer();
    ~Enforcer();

    void move();
    void restart();
    virtual void attack(BulletList &b);
};

#endif