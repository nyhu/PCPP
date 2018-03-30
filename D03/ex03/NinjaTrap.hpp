#ifndef __NINJA_TRAP__
#define __NINJA_TRAP__

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{
public:
  NinjaTrap();
  NinjaTrap(const std::string name);
  NinjaTrap(const NinjaTrap &NinjaTrap);
  ~NinjaTrap();

  NinjaTrap &operator=(const NinjaTrap &f);

  void ninjaShoebox(ClapTrap &t);
  void ninjaShoebox(FragTrap &t);
  void ninjaShoebox(ScavTrap &t);
  void ninjaShoebox(NinjaTrap &t);

private:
  void setDefaultSpec(std::string const &name);
};

#endif