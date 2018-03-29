#include "ClapTrap.hpp"

void ClapTrap::annonce(void)
{
    std::cout << "A new "
              << this->_type
              << " called "
              << this->_name
              << " emerge from the dump"
              << std::endl;
}

void ClapTrap::denonce(void)
{
    std::cout << "And yet again a "
              << this->_type
              << " called "
              << this->_name
              << " being fragged back to the dump"
              << std::endl;
}

ClapTrap::ClapTrap() : _name("UnkownScavBox"),
                       _lvl(1),
                       _type("Cl4P-TP"),
                       _hitPt(100),
                       _maxHitPt(100),
                       _energyPt(50),
                       _maxEnergyPt(50),
                       _meleeDmg(20),
                       _rangeDmg(15),
                       _armorDmgReduction(3)
{
    srand(time(0));
    this->annonce();
}

ClapTrap::ClapTrap(const std::string name) : _name(name),
                                             _lvl(1),
                                             _type("Cl4P-TP"),
                                             _hitPt(100),
                                             _maxHitPt(100),
                                             _energyPt(50),
                                             _maxEnergyPt(50),
                                             _meleeDmg(20),
                                             _rangeDmg(15),
                                             _armorDmgReduction(3)
{
    srand(time(0));
    this->annonce();
}

ClapTrap::ClapTrap(const ClapTrap &f) : _name(f._name),
                                        _lvl(f._lvl),
                                        _type("Cl4P-TP"),
                                        _hitPt(f._hitPt),
                                        _maxHitPt(f._maxHitPt),
                                        _energyPt(f._energyPt),
                                        _maxEnergyPt(f._maxEnergyPt),
                                        _meleeDmg(f._meleeDmg),
                                        _rangeDmg(f._rangeDmg),
                                        _armorDmgReduction(f._armorDmgReduction)
{
    srand(time(0));
    this->annonce();
}

ClapTrap::~ClapTrap()
{
    std::cout << "And yet again a CL4P-TP called "
              << this->_name
              << " being fragged back to the dump"
              << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &f)
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

void ClapTrap::meleeAttack(const std::string &target)
{
    std::cout << this->_type
              << " "
              << this->_name
              << " attack "
              << target
              << " with his arm causing "
              << this->_meleeDmg
              << " damages points !"
              << std::endl;
}

void ClapTrap::rangeAttack(const std::string &target)
{
    std::cout << this->_type
              << " "
              << this->_name
              << " attack "
              << target
              << " throwing a bottle causing "
              << this->_rangeDmg
              << " damages points !"
              << std::endl;
}

void ClapTrap::takeDmg(unsigned int amount)
{
    if ((unsigned int)(this->_armorDmgReduction) < amount)
    {
        this->_hitPt -= (amount - this->_armorDmgReduction);
        if (this->_hitPt <= 0)
        {
            this->_hitPt = 0;
            std::cout << this->_type
                      << " "
                      << this->_name
                      << " takes "
                      << (amount - this->_armorDmgReduction)
                      << " hit points, and lies now on the floor, waiting for the end of the combat !"
                      << std::endl;
        }
        else
        {
            std::cout << this->_type
                      << " "
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
        std::cout << this->_type
                  << " "
                  << this->_name
                  << " takes no damage from the attack !"
                  << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    int mem = this->_hitPt;
    this->_hitPt += amount;
    if (this->_hitPt > this->_maxHitPt)
    {
        this->_hitPt = this->_maxHitPt;
    }
    std::cout << this->_type
              << " "
              << this->_name
              << " was repared for "
              << (this->_hitPt - mem)
              << std::endl;
}
