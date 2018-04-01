#ifndef __ISHIP__
#define __ISHIP__

#include "AShip.hpp"

class IShip : public AShip
{
  public:
    virtual ~IShip() {}
    virtual AShip *attack() = 0;
};

#endif