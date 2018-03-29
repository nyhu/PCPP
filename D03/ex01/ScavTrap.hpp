#ifndef __SCAV_TRAP__
#define __SCAV_TRAP__

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class ScavTrap {
public:
    ScavTrap();
    ScavTrap(const std::string name);
    ScavTrap(const ScavTrap &s);
    ~ScavTrap();

    ScavTrap &operator=(const ScavTrap &f);

    void meleeAttack(const std::string &target);
    void rangeAttack(const std::string &target);
    void challengeNewcommer(const std::string &target);

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

    void _vaultChallenge0(const std::string &target);
    void _vaultChallenge1(const std::string &target);
    void _vaultChallenge2(const std::string &target);
    void _vaultChallenge3(const std::string &target);
    void _vaultChallenge4(const std::string &target);

};

#endif