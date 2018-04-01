#ifndef __ISHIP__
#define __ISHIP__

#include "AShip.hpp"
#include "../bullets/BulletList.hpp"

class IShip : public AShip
{
  public:
    virtual ~IShip() {}
    virtual void attack(BulletList &bullet) = 0;
};

#endif