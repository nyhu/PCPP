#ifndef __INTERN__
#define __INTERN__

#include <string>

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
  public:
    Intern();
    ~Intern();

    Form *makeForm(std::string const name, std::string const target);
};

#endif