#include "Weapon.hpp"

Weapon::Weapon() {
    this->_type = "BearHands";
}

Weapon::Weapon(std::string type) : _type(type) {  
}

void Weapon::setType(std::string type) {
    this->_type = type;
}

std::string Weapon::getType(void) {
    return this->_type;
}
