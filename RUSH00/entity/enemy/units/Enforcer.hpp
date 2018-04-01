#ifndef __ENFORCER__
#define __ENFORCER__

#include "../../ships/IShip.hpp"
#include "../../bullets/BulletList.hpp"

class Enforcer : public IShip
{
  public:
    Enforcer();
    virtual ~Enforcer();
    Enforcer(Enforcer const & src);
    Enforcer &operator=(const Enforcer &rhs);

    void move();
    void restart();
    virtual void attack(BulletList &b);
};

#endif