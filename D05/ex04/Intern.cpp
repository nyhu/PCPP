#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(Intern const &Intern)
{
    (void)Intern;
}
Intern::~Intern() {}
Intern &Intern::operator=(Intern const &i)
{
    (void)i;
    return *this;
}

Form *Intern::makeForm(std::string const name, std::string const target)
{
    Form *f;
    size_t ko = std::string::npos;

    if (ko != name.find("robot") || ko != name.find("robotomy"))
    {
        f = new RobotomyRequestForm(target);
        std::cout << "Intern Creates " << *f << std::endl;
        return f;
    }
    if (ko != name.find("tree") || ko != name.find("shrubbery"))
    {
        f = new ShrubberyCreationForm(target);
        std::cout << "Intern Creates " << *f << std::endl;
        return f;
    }
    if (ko != name.find("pardon") || ko != name.find("president") || ko != name.find("presidential"))
    {
        f = new PresidentialPardonForm(target);
        std::cout << "Intern Creates " << *f << std::endl;
        return f;
    }

    std::cout << "Intern doesn't know what to do with " << target << "!" << std::endl;
    return NULL;
}
