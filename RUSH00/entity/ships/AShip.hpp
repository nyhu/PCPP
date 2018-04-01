#ifndef __ASHIP__
#define __ASHIP__

#include <ctime>
#include <cstdlib>

// #include "../weapons/IWeapon.hpp"
#include "../../settings/settings.hpp"

class AShip
{
  public:
    AShip();
    ~AShip();

    virtual void move();
    void stop();
    // IBullets *attack();
    void collide(AShip &s);

    void setDirection(int x, int y);
    void setPosition(int x, int y);
    int getPosX();
    int getPosY();
    char getOutput();
    int getPv();

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