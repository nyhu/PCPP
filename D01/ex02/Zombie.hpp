#ifndef __ZOMBIE__
#define __ZOMBIE__

#include <string>

class Zombie
{
  public:
    Zombie(std::string name, std::string type);
    ~Zombie();

    void annonce(void);

    std::string name;
    std::string type;
};

#endif