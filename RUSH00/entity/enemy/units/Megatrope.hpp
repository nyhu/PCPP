#ifndef __MEGATROPE__
#define __MEGATROPE__

#include "../../ships/IShip.hpp"

class Megatrope : public IShip
{
  public:
    Megatrope();
    ~Megatrope();

    void move();
    void respawn();
    virtual void attack(BulletList &b);
};

#endif