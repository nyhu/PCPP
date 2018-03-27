#include <iostream>
#include "Pony.hpp"

int Pony::ponyInstanceNb = 0;

Pony::Pony()
{
    Pony::ponyInstanceNb++;
    std::cout << "A ponny is born" << std::endl;
}

void Pony::run(int distance)
{
    std::cout << "I run "
              << distance
              << " kilometer with you on my back"
              << std::endl;
}

void Pony::flapTail(int nb)
{
    std::cout << "I flap my tail "
              << nb
              << " time, isn't it cute?"
              << std::endl;
}

Pony::~Pony()
{
    Pony::ponyInstanceNb--;    
    std::cout << "A ponny is dead" << std::endl;
}

void ponyOnTheHeap()
{
    Pony *pony = new Pony();
    pony->run(1);
    delete pony;
}

void ponyOnTheStack()
{
    Pony pony;
    pony.flapTail(2);
}
