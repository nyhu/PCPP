#include "Human.hpp"

std::string Human::identify(void) {
    return this->_brain.identify();    
}

Brain& Human::getBrain() {
    return this->_brain;
}