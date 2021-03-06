#ifndef __ASHIP__
#define __ASHIP__

#include <ctime>
#include <cstdlib>

#include "../../settings/settings.hpp"

class AShip
{
  public:
    AShip();
    AShip(int pv, char ouput, int posX, int posY, int directionX, int directionY);
    virtual ~AShip();
    AShip(AShip const & src);
    AShip &operator=(const AShip &rhs);



    virtual void move();
    void stop();
    virtual void respawn();
    int collide(AShip &s);

    void setDirection(int x, int y);
    void setPosition(int x, int y);
    bool touchBorder();
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
    short frameSinceLastAttack;
};

#endif