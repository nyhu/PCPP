#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat jean("JVD", 5);
		ShrubberyCreationForm b234("b234");
		ShrubberyCreationForm copy_file("b234_copy");
		copy_file = b234;
		jean.signForm(copy_file);
		jean.executeForm(copy_file);

		PresidentialPardonForm president("rbadia");
		jean.signForm(president);
		jean.executeForm(president);

		RobotomyRequestForm robot("jye");
		jean.signForm(robot);
		jean.executeForm(robot);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat slave("hobo", 150);
		Bureaucrat paysan("kevin", 100);
		PresidentialPardonForm president("macron");
		ShrubberyCreationForm work("trees");
		RobotomyRequestForm robot("robot");
		slave.executeForm(president);
		slave.executeForm(work);
		paysan.executeForm(robot);
		paysan.executeForm(work);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
