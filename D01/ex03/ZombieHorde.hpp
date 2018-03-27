#ifndef __ZOMBIEHORDE__
#define __ZOMBIEHORDE__
#include <iostream>
#include "Zombie.hpp"

class ZombieHorde {
public:
    ZombieHorde(int nb);
    ~ZombieHorde();

    void annonce(void);

private:
    int _nb;
    Zombie *_zombies;
};

 #endif