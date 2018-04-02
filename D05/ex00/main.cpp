#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat arthur("CEO", 1);
    Bureaucrat peon("soldier", 150);

    std::cout << arthur << std::endl;
    std::cout << peon << std::endl;

    try {
        Bureaucrat toto("test", 151);
    } catch (Bureaucrat::GradeTooLowException e) {
        std::cout << "exeption too low effective" << std::endl;
    }

    try {
        Bureaucrat tata("test", 0);
    } catch (Bureaucrat::GradeTooHighException e) {
        std::cout << "exeption too high effective" << std::endl;
    }

    try {
        peon.decrementGrade();
    } catch (Bureaucrat::GradeTooLowException e) {
        std::cout << "exeption decrem grade too low effective" << std::endl;
    }

    try {
        arthur.incrementGrade();
    } catch (Bureaucrat::GradeTooHighException e) {
        std::cout << "exeption incremt grade too high effective" << std::endl;
    }
    
    return 0;
}