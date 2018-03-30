#ifndef __SUPER_TRAP__
#define __SUPER_TRAP__

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{
public:
  SuperTrap();
  SuperTrap(const std::string name);
  SuperTrap(const SuperTrap &s);
  ~SuperTrap();

  SuperTrap &operator=(const SuperTrap &f);

private:
  void setDefaultSpec(std::string const &name);
};

#endif