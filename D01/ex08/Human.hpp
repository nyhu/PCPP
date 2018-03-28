#ifndef __HUMAN__
#define __HUMAN__

#include <string>
#include <iostream>
#include <map>

class Human
{
  private:
    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);
    void intimidatingShout(std::string const &target);

  public:
    void action(std::string const &action_name, std::string const &target);
};

#endif