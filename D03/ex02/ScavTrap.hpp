#ifndef __SCAV_TRAP__
#define __SCAV_TRAP__

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
  ScavTrap();
  ScavTrap(const std::string name);
  ScavTrap(const ScavTrap &s);
  ~ScavTrap();

  ScavTrap &operator=(const ScavTrap &f);

  void challengeNewcommer(const std::string &target);

private:
  void setDefaultSpec(std::string const &name);
  
  void _vaultChallenge0(const std::string &target);
  void _vaultChallenge1(const std::string &target);
  void _vaultChallenge2(const std::string &target);
  void _vaultChallenge3(const std::string &target);
  void _vaultChallenge4(const std::string &target);
};

#endif