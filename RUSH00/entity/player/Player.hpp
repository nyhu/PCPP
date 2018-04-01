#ifndef __PLAYER__
#define __PLAYER__

#include <curses.h>
#include "../ships/IShip.hpp"

class Player : public IShip
{
  public:
    Player();
    Player(int x, int y);
    Player(const Player &p);
    virtual ~Player();
    Player &operator=(const Player &rhs);

    bool control(int input);
    bool controlP2(int input);

    int getLives();
    void die();

    virtual void attack(BulletList &b);
    void move();

    long score;
    BulletList bullets;

    virtual void respawn();
    private:
    int lives;
};

#endif