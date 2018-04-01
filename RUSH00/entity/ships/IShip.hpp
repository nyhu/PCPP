#ifndef __ISHIP__
#define __ISHIP__

#include "AShip.hpp"

class IShip : public AShip
{
  public:
    virtual ~IShip() {}
    // virtual IBullets *attack();
};

#endif