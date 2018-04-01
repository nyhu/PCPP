#ifndef __PLAYER__
#define __PLAYER__

#include <curses.h>
#include "../ships/IShip.hpp"

class Player : public IShip
{
    public:
    Player();
    Player(const Player &p);
    ~Player();

    bool control(int input);
    bool controlP2(int input);
    int getLives();
    void die();

    AShip *attack();
    virtual void respawn();
    private:
    int lives;
};

#endif