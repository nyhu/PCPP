#ifndef __WEAPON__
#define __WEAPON__

#include <string>

class Weapon {
public:

    Weapon();
    Weapon(std::string type);
    void setType(std::string type);
    std::string getType();
private:
    std::string _type;
};

#endif