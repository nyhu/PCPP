#ifndef __ASHIP__
#define __ASHIP__

// #include "../weapons/IWeapon.hpp"
#include "../../settings/settings.hpp"

class AShip
{
  public:
    AShip();
    ~AShip();

    virtual void move();
    virtual void setDirection(int x, int y);
    int getPosX();
    int getPosY();
    char getOutput();
    // IBullets *attack();

  protected:
    // IWeapon *weapon;
    int pv;
    char ouput;
    int posX;
    int posY;
    short directionX;
    short directionY;
};

#endif