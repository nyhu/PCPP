#ifndef __FIGHTER__
#define __FIGHTER__

#include "../../ships/IShip.hpp"

class Fighter : public IShip
{
  public:
    Fighter();
    ~Fighter();
    Fighter(Fighter const & src);
    Fighter &operator=(const Fighter &rhs);


    void move();
    void restart();
    virtual void attack(BulletList &b);
};

#endif