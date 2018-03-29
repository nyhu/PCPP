#ifndef __FRAG_TRAP__
#define __FRAG_TRAP__


#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class FragTrap
{
  public:
    FragTrap(const std::string name);
    FragTrap(const FragTrap &fragTrap);
    ~FragTrap();

    FragTrap &operator=(const FragTrap &f);

    void meleeAttack(const std::string &target);
    void rangeAttack(const std::string &target);
    void vaulthunter_dot_exe(const std::string &target);

    void takeDmg(unsigned int amount);
    void beRepaired(unsigned int amount);


  private:
    std::string _name;
    int _lvl;

    int _hitPt;
    const int _maxHitPt;

    int _energyPt;
    const int _maxEnergyPt;

    int _meleeDmg;
    int _rangeDmg;
    int _armorDmgReduction;

    void _vaultAttack0(const std::string &target);
    void _vaultAttack1(const std::string &target);
    void _vaultAttack2(const std::string &target);
    void _vaultAttack3(const std::string &target);
    void _vaultAttack4(const std::string &target);
};

#endif