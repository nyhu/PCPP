#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) : Form("RobotomyRequestForm", 72, 45, target)
{
	srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : Form(src)
{
	srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	((Form &)*this) = (Form &)rhs;
	return *this;
}

void RobotomyRequestForm::exe(Bureaucrat const & b) const
{
	(void)b;
	system(DRILL_MAN);

	if (rand() % 2)
		std::cout << "<" << this->getTarget() << "> has been robotomized successfully" << std::endl;
	else
		std::cout << "<" << this->getTarget() << "> has failed to get robotomized..." << std::endl;
}
