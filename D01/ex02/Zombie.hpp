#ifndef __ZOMBIE__
#define __ZOMBIE__
#define ZOMBIE_DEFAULT_TYPE "walker"

#include <string>
class Zombie
{
  public:
    Zombie(std::string name, std::string type = ZOMBIE_DEFAULT_TYPE);
    Zombie();
    ~Zombie();

    void annonce(void);
    void setName(std::string name);

    std::string name;
    std::string type;
};

std::string getRandomZombieName(void); 

#endif