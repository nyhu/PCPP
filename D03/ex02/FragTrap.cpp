#include "FragTrap.hpp"

void FragTrap::setDefaultSpec(std::string const &name)
{
    srand(time(0));
    this->_type = "FR4G-TP";
    this->_name = name;
    this->_energyPt = 100;
    this->_maxEnergyPt = 100;
    this->_meleeDmg = 30;
    this->_rangeDmg = 20;
    this->_armorDmgReduction = 5;
}

FragTrap::FragTrap() : ClapTrap()
{
    this->setDefaultSpec("unkownFragBox");
    this->annonce();
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    this->setDefaultSpec(name);
    this->annonce();
}

FragTrap::FragTrap(const FragTrap &f) : ClapTrap()
{
    *this = f;
    this->annonce();
}

FragTrap::~FragTrap()
{
    this->denonce();
}

FragTrap &FragTrap::operator=(const FragTrap &f)
{
    this->_type = f._type;
    this->_name = f._name;
    this->_lvl = f._lvl;
    this->_hitPt = f._hitPt;
    this->_maxHitPt = f._maxHitPt;
    this->_energyPt = f._energyPt;
    this->_maxEnergyPt = f._maxEnergyPt;
    this->_meleeDmg = f._meleeDmg;
    this->_rangeDmg = f._rangeDmg;
    this->_armorDmgReduction = f._armorDmgReduction;

    return *this;
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
