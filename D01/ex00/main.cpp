#include <iostream>
#include "Pony.hpp"

static void printPonyNumber()
{
    std::cout << "there are "
              << Pony::ponyInstanceNb
              << " ponies in the fields"
              << std::endl;
}

int main()
{
    printPonyNumber();
    ponyOnTheHeap();
    ponyOnTheStack();
    printPonyNumber();
    return 0;
}