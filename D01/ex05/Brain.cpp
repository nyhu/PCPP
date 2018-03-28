#include <sstream>
#include "Brain.hpp"

std::string Brain::identify(void) {
    std::stringstream s;
    s << this;
    return s.str();
}