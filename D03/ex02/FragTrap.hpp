#ifndef __FRAG_TRAP__
#define __FRAG_TRAP__

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
  FragTrap();
  FragTrap(const std::string name);
  FragTrap(const FragTrap &fragTrap);
  ~FragTrap();

  FragTrap &operator=(const FragTrap &f);

  void vaulthunter_dot_exe(const std::string &target);

private:
  void setDefaultSpec(std::string const &name);

  void _vaultAttack0(const std::string &target);
  void _vaultAttack1(const std::string &target);
  void _vaultAttack2(const std::string &target);
  void _vaultAttack3(const std::string &target);
  void _vaultAttack4(const std::string &target);
};

#endif