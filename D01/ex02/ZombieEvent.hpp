#ifndef __ZOMBIEEVENT__
#define __ZOMBIEEVENT__

#include <string>
#include "Zombie.hpp"

class ZombieEvent
{
  public:
    ZombieEvent();
    ~ZombieEvent();

    void setZombieType(std::string type);
    Zombie *newZombie(std::string name);
    void randomChump();

  private:
    std::string type;
};

#endif