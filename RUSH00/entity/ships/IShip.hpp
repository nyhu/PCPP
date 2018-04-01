#ifndef __ISHIP__
#define __ISHIP__

#include "../bullets/BulletList.hpp"

class IShip : public AShip
{
  public:
    virtual void attack(BulletList &b) = 0;
    virtual ~IShip() {};
};

#endif