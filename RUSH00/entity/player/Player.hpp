#ifndef __PLAYER__
#define __PLAYER__

#include <curses.h>
#include "../ships/IShip.hpp"
#include "../bullets/BulletList.hpp"

class Player : public IShip
{
  public:
    Player();
    Player(int x, int y);
    Player(const Player &p);
    ~Player();

    bool control(int input);
    bool controlP2(int input);
    int getLives();
    void die();

    AShip *attack();
    void move();

    long score;
    BulletList bullets;

    virtual void respawn();
    private:
    int lives;
};

#endif