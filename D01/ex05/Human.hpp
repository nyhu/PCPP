#ifndef __HUMAN__
#define __HUMAN__

#include "Brain.hpp"

class Human {
public:
    std::string identify(void);
    Brain& getBrain(void);
private:
    Brain _brain;
};

#endif