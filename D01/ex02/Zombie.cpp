#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(std::string name, std::string type) : name(name), type(type) {
}

Zombie::~Zombie()
{
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