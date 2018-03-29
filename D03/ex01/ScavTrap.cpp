#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _name("UnkownScavBox"),
                       _lvl(1),
                       _hitPt(100),
                       _maxHitPt(100),
                       _energyPt(50),
                       _maxEnergyPt(50),
                       _meleeDmg(20),
                       _rangeDmg(15),
                       _armorDmgReduction(3)
{
    srand(time(0));
    std::cout << "A new SC4V-TP called UnkownScavBox emerge from the dump"
              << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : _name(name),
                                             _lvl(1),
                                             _hitPt(100),
                                             _maxHitPt(100),
                                             _energyPt(50),
                                             _maxEnergyPt(50),
                                             _meleeDmg(20),
                                             _rangeDmg(15),
                                             _armorDmgReduction(3)
{
    srand(time(0));
    std::cout << "A new SC4V-TP called "
              << name
              << " emerge from the dump"
              << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &f) : _name(f._name),
                                        _lvl(f._lvl),
                                        _hitPt(f._hitPt),
                                        _maxHitPt(f._maxHitPt),
                                        _energyPt(f._energyPt),
                                        _maxEnergyPt(f._maxEnergyPt),
                                        _meleeDmg(f._meleeDmg),
                                        _rangeDmg(f._rangeDmg),
                                        _armorDmgReduction(f._armorDmgReduction)
{
    srand(time(0));
    std::cout << "A new SC4V-TP called "
              << f._name
              << " emerge from the dump"
              << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "And yet again a SC4V-TP called "
              << this->_name
              << " being fragged back to the dump"
              << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &f)
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

void ScavTrap::meleeAttack(const std::string &target)
{
    std::cout << "SC4V-TP "
              << this->_name
              << " attack "
              << target
              << " with his arm causing "
              << this->_meleeDmg
              << " damages points !"
              << std::endl;
}

void ScavTrap::rangeAttack(const std::string &target)
{
    std::cout << "SC4V-TP "
              << this->_name
              << " attack "
              << target
              << " throwing a bottle causing "
              << this->_rangeDmg
              << " damages points !"
              << std::endl;
}

void ScavTrap::challengeNewcommer(const std::string &target)
{
    typedef void (ScavTrap::*vaultChallenge)(const std::string &target);
    static vaultChallenge challengesArr[] = {
        &ScavTrap::_vaultChallenge0,
        &ScavTrap::_vaultChallenge1,
        &ScavTrap::_vaultChallenge2,
        &ScavTrap::_vaultChallenge3,
        &ScavTrap::_vaultChallenge4,
    };

    if (this->_energyPt >= 25)
    {
        this->_energyPt -= 25;
        (this->*(challengesArr[rand() % 5]))(target);
    }
    else
    {
        std::cout << "due to nrj lvl, "
                  << this->_name
                  << " is unable to perform a vaultChallenge yet !"
                  << std::endl;
    }
}

void ScavTrap::_vaultChallenge0(const std::string &target)
{
    std::cout << "SC4V-TP "
              << this->_name
              << " vaultChallenge "
              << target
              << " to find A RUSTY BOX throwing bottles so hard they become yellow !!!"
              << std::endl;
}

void ScavTrap::_vaultChallenge1(const std::string &target)
{
    std::cout << "SC4V-TP "
              << this->_name
              << " vaultChallenge "
              << target
              << " to  SPINNNNNN until it reaches the moon"
              << std::endl;
}

void ScavTrap::_vaultChallenge2(const std::string &target)
{
    std::cout << "SC4V-TP "
              << this->_name
              << " vaultChallenge "
              << target
              << " to end the game in the strongest difficulty !"
              << std::endl;
}

void ScavTrap::_vaultChallenge3(const std::string &target)
{
    std::cout << "SC4V-TP "
              << this->_name
              << " vaultChallenge "
              << target
              << " like NEVER BEFORE, he'll have to do the next mission naked ! This game is allready above PEGI 18 anyway."
              << std::endl;
}

void ScavTrap::_vaultChallenge4(const std::string &target)
{
    std::cout << "SC4V-TP "
              << this->_name
              << " vaultChallenge "
              << target
              << " to fart on a wild animal before running, not along the way !"
              << std::endl;
}

void ScavTrap::takeDmg(unsigned int amount)
{
    if ((unsigned int)(this->_armorDmgReduction) < amount)
    {
        this->_hitPt -= (amount - this->_armorDmgReduction);
        if (this->_hitPt <= 0)
        {
            this->_hitPt = 0;
            std::cout << "SC4V-TP "
                      << this->_name
                      << " takes "
                      << (amount - this->_armorDmgReduction)
                      << " hit points, and lies now on the floor, waiting for the end of the combat !"
                      << std::endl;
        }
        else
        {
            std::cout << "SC4V-TP "
                      << this->_name
                      << " takes "
                      << (amount - this->_armorDmgReduction)
                      << " hit points, it still get "
                      << this->_hitPt
                      << " left !"
                      << std::endl;
        }
    }
    else
    {
        std::cout << "SC4V-TP "
                  << this->_name
                  << " takes no damage from the attack !"
                  << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    int mem = this->_hitPt;
    this->_hitPt += amount;
    if (this->_hitPt > this->_maxHitPt)
    {
        this->_hitPt = this->_maxHitPt;
    }
    std::cout << "SC4V-TP "
              << this->_name
              << " was repared for "
              << (this->_hitPt - mem)
              << std::endl;
}
