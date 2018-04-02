#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Form *f;
	Intern studentAt42;

	f = studentAt42.makeForm("robot", "olag");
	std::cout << *f << std::endl;
	delete f;

	f = studentAt42.makeForm("tree", "adam");
	std::cout << *f << std::endl;
	delete f;

	f = studentAt42.makeForm("president", "osef");
	std::cout << *f << std::endl;
	delete f;

	f = studentAt42.makeForm("unkown", "jojo");
	if (f)
		std::cout << *f << std::endl;
	delete f;

	return 0;
}
