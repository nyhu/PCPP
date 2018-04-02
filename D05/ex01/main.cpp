#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat arthur("CEO", 1);
    Bureaucrat peon("soldier", 150);

    std::cout << arthur << std::endl;
    std::cout << peon << std::endl;

    Form buyBeer("beer", 150, 150);
    Form declareeWar("war", 1, 1);

    peon.signForm(buyBeer);
    peon.signForm(declareeWar);
    arthur.signForm(declareeWar);

    if (buyBeer.isSigned() && declareeWar.isSigned())
        std::cout << "All contract was succesfully singned" << std::endl;

    return 0;
}