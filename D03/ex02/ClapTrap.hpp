#ifndef __CLAP_TRAP__
#define __CLAP_TRAP__

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class ClapTrap
{
  public:
    ClapTrap();
    ClapTrap(const std::string name);
    ClapTrap(const ClapTrap &s);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &f);

    void meleeAttack(const std::string &target);
    void rangeAttack(const std::string &target);

    void takeDmg(unsigned int amount);
    void beRepaired(unsigned int amount);

  protected:
    std::string _name;
    int _lvl;
    std::string _type;

    int _hitPt;
    int _maxHitPt;

    int _energyPt;
    int _maxEnergyPt;

    int _meleeDmg;
    int _rangeDmg;
    int _armorDmgReduction;

    void annonce();
    void denonce();
};

#endif