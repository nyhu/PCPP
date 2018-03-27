#include <iostream>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string &refBrain = brain;
    std::string *ptrBrain = &brain;

    std::cout << *ptrBrain << std::endl;
    std::cout << refBrain << std::endl;
    
    return 0;
}