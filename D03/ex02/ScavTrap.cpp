#include "ScavTrap.hpp"

void ScavTrap::setDefaultSpec(std::string const &name)
{
    srand(time(0));
    this->_type = "SC4V-TP";
    this->_name = name;
    this->_energyPt = 50;
    this->_maxEnergyPt = 50;
    this->_meleeDmg = 20;
    this->_rangeDmg = 15;
    this->_armorDmgReduction = 3;
}

ScavTrap::ScavTrap() : ClapTrap()
{
    this->setDefaultSpec("UnkownScavBox");
    this->annonce();
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    this->setDefaultSpec(name);
    this->annonce();
}

ScavTrap::ScavTrap(const ScavTrap &f) : ClapTrap()
{
    *this = f;
    this->annonce();
}

ScavTrap::~ScavTrap()
{
    this->denonce();
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
