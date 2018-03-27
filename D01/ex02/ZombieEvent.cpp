#include <cstdlib>
#include <ctime>
#include <iostream>
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
    this->type = ZOMBIE_DEFAULT_TYPE;
    std::cout << "walker zombies will soon arise" << std::endl;
    srand(time(0));
}

ZombieEvent::~ZombieEvent()
{
}

void ZombieEvent::setZombieType(std::string type)
{
    this->type = type;
    std::cout << type << " zombies will soon arise" << std::endl;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
    return new Zombie(name, this->type);
}

void ZombieEvent::randomChump()
{
    std::string tab[] = {
        "budz",
        "pain",
        "konan",
        "nagato",
        "itachi",
        "tobi",
        "madara",
        "naruto",
        "danzou",
        "kakashi",
    };

    std::string name = tab[rand() % (sizeof(tab) / sizeof(tab[0]))];

    Zombie zombie(name, this->type);
    zombie.annonce();
}