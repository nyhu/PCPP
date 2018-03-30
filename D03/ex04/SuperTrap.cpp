#include "SuperTrap.hpp"

void SuperTrap::setDefaultSpec(std::string const &name)
{
    srand(time(0));
    this->_type = "SUPR-TP";
    this->_name = name;
    this->_hitPt = 100;
    this->_maxHitPt = 100;
    this->_energyPt = 120;
    this->_maxEnergyPt = 120;
    this->_meleeDmg = 60;
    this->_rangeDmg = 20;
    this->_armorDmgReduction = 5;
}

SuperTrap::SuperTrap() : NinjaTrap(), FragTrap()
{
    this->setDefaultSpec("UnkownSuperBox");
    this->annonce();
}

SuperTrap::SuperTrap(const std::string name) : NinjaTrap(name), FragTrap(name)
{
    this->setDefaultSpec(name);
    this->annonce();
}

SuperTrap::SuperTrap(const SuperTrap &f) : NinjaTrap(), FragTrap()
{
    *this = f;
    this->annonce();
}

SuperTrap::~SuperTrap()
{
    this->denonce();
}

SuperTrap &SuperTrap::operator=(const SuperTrap &f)
{
    this->_name = f._name;
    this->_lvl = f._lvl;
    this->_hitPt = f._hitPt;
    this->_energyPt = f._energyPt;
    this->_meleeDmg = f._meleeDmg;
    this->_rangeDmg = f._rangeDmg;
    this->_armorDmgReduction = f._armorDmgReduction;

    return *this;
}
