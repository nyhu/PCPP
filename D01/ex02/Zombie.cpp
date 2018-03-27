#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Zombie.hpp"


Zombie::Zombie(std::string name, std::string type)
    : name(name), type(type) {}

Zombie::Zombie() {
    srand(time(0));
    this->name = getRandomZombieName();
    this->type = ZOMBIE_DEFAULT_TYPE;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::annonce(void)
{
    std::cout << "<"
              << this->name
              << " ("
              << this->type
              << ")> Braiiiiiiinnnssss..."
              << std::endl;
}

Zombie::~Zombie() {}

std::string getRandomZombieName() {
    std::string zombieDefaultNames[] = {
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

    return zombieDefaultNames[rand() % (sizeof(zombieDefaultNames) / sizeof(zombieDefaultNames[0]))];
}
