#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int nb) : _nb(nb) {
    std::cout << "horde is rising" << std::endl;
    this->_zombies = new Zombie[nb];
    for (int i = 0; i < this->_nb; i++) {
        this->_zombies[i].setName(getRandomZombieName());
    }
    this->annonce();
}

ZombieHorde::~ZombieHorde() {
    std::cout << "horde is dead" << std::endl;
    delete [] this->_zombies;
}

void ZombieHorde::annonce(void){
    std::cout << "horde is yelling" << std::endl;
    for (int i = 0; i < this->_nb; i++) {
        this->_zombies[i].annonce();
    }
}
