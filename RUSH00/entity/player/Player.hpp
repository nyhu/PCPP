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

    void control(int input);
};

#endif