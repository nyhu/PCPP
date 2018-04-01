#ifndef __PLAYER__
#define __PLAYER__

#include <curses.h>
#include "../ships/AShip.hpp"

class Player : public AShip
{
    public:
    Player();
    Player(const Player &p);
    ~Player();

    void control(int input);
};

#endif