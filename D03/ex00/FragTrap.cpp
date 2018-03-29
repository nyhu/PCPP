#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : _name(name),
                                             _lvl(1),
                                             _hitPt(100),
                                             _maxHitPt(100),
                                             _energyPt(100),
                                             _maxEnergyPt(100),
                                             _meleeDmg(30),
                                             _rangeDmg(20),
                                             _armorDmgReduction(5)
{
    srand(time(0));
    std::cout << "A new FR4G-TP called "
              << name
              << " emerge from the dump"
              << std::endl;
}

FragTrap::FragTrap(const FragTrap &f) : _name(f._name),
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
    std::cout << "A new FR4G-TP called "
              << f._name
              << " emerge from the dump"
              << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "And yet again a FR4G-TP called "
              << this->_name
              << " being fragged back to the dump"
              << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &f)
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

void FragTrap::meleeAttack(const std::string &target)
{
    std::cout << "FR4G-TP "
              << this->_name
              << " attack "
              << target
              << " with his arm causing "
              << this->_meleeDmg
              << " damages points !"
              << std::endl;
}

void FragTrap::rangeAttack(const std::string &target)
{
    std::cout << "FR4G-TP "
              << this->_name
              << " attack "
              << target
              << " throwing a bottle causing "
              << this->_rangeDmg
              << " damages points !"
              << std::endl;
}

void FragTrap::vaulthunter_dot_exe(const std::string &target)
{
    typedef void (FragTrap::*vaultAttack)(const std::string &target);
    static vaultAttack attacksArr[] = {
        &FragTrap::_vaultAttack0,
        &FragTrap::_vaultAttack1,
        &FragTrap::_vaultAttack2,
        &FragTrap::_vaultAttack3,
        &FragTrap::_vaultAttack4,
    };

    if (this->_energyPt >= 25)
    {
        this->_energyPt -= 25;
        (this->*(attacksArr[rand() % 5]))(target);
    }
    else
    {
        std::cout << "due to nrj lvl, "
                  << this->_name
                  << " is unable to perform a vaultAttack yet !"
                  << std::endl;
    }
}

void FragTrap::_vaultAttack0(const std::string &target)
{
    std::cout << "FR4G-TP "
              << this->_name
              << " vaultAttack "
              << target
              << " as A BANANA dangling monkey throwing bottle so hard they become yellow, it does 3 x "
              << this->_rangeDmg
              << " damages points !!!"
              << std::endl;
}

void FragTrap::_vaultAttack1(const std::string &target)
{
    std::cout << "FR4G-TP "
              << this->_name
              << " vaultAttack "
              << target
              << " as A SPINNNNNNING BOT, it does 3 x "
              << this->_meleeDmg
              << " damages points !!!"
              << std::endl;
}

void FragTrap::_vaultAttack2(const std::string &target)
{
    std::cout << "FR4G-TP "
              << this->_name
              << " vaultAttack "
              << target
              << " like a baby, it does only "
              << 1
              << " damages points !!! What's a shame"
              << std::endl;
}

void FragTrap::_vaultAttack3(const std::string &target)
{
    std::cout << "FR4G-TP "
              << this->_name
              << " vaultAttack "
              << target
              << " like NEVER BEFORE, it does an instaant "
              << 100
              << " damages points !!! The bandit will never survive this !"
              << std::endl;
}

void FragTrap::_vaultAttack4(const std::string &target)
{
    std::cout << "FR4G-TP "
              << this->_name
              << " vaultAttack "
              << target
              << " like a GASOLINE ROCKET, it flies up and falls on the target doing "
              << 70
              << " damages points !!! Marvellous !"
              << std::endl;
}

void FragTrap::takeDmg(unsigned int amount)
{
    if ((unsigned int)(this->_armorDmgReduction) < amount)
    {
        this->_hitPt -= (amount - this->_armorDmgReduction);
        if (this->_hitPt <= 0)
        {
            this->_hitPt = 0;
            std::cout << "FR4G-TP "
                      << this->_name
                      << " takes "
                      << (amount - this->_armorDmgReduction)
                      << " hit points, and lies now on the floor, waiting for the end of the combat !"
                      << std::endl;
        }
        else
        {
            std::cout << "FR4G-TP "
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
        std::cout << "FR4G-TP "
                  << this->_name
                  << " takes no damage from the attack !"
                  << std::endl;
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    int mem = this->_hitPt;
    this->_hitPt += amount;
    if (this->_hitPt > this->_maxHitPt)
    {
        this->_hitPt = this->_maxHitPt;
    }
    std::cout << "FR4G-TP "
              << this->_name
              << " was repared for "
              << (this->_hitPt - mem)
              << std::endl;
}
