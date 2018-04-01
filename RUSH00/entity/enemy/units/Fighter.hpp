#ifndef __FIGHTER__
#define __FIGHTER__

#include "../../ships/IShip.hpp"

class Fighter : public IShip
{
  public:
    Fighter();
    ~Fighter();

    void move();
    AShip *attack();
};

#endif