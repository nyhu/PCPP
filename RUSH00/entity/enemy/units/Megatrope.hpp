#ifndef __MEGATROPE__
#define __MEGATROPE__

#include "../../ships/IShip.hpp"

class Megatrope : public IShip
{
  public:
    Megatrope();
    ~Megatrope();

    void move();
    virtual void attack(BulletList &b);
};

#endif