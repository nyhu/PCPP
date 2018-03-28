#ifndef __HUMAN_B__
#define __HUMAN_B__

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanB {
public:
    HumanB(std::string name);
    void setWeapon(Weapon &weapon);
    void attack() const;
private:
    std::string _name;
    Weapon *_weapon;
    Weapon _defaultWeapon;
};

#endif