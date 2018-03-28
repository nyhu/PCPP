#ifndef __HUMAN_A__
#define __HUMAN_A__

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanA {
public:
    HumanA(std::string name, Weapon &weapon);
    void attack() const;
private:
    std::string _name;
    Weapon &_weapon;
};

#endif