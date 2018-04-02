#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#ifdef LINUX
# define DRILL_MAN "play Drill.mp3"
#else
# define DRILL_MAN "afplay Drill.mp3"
#endif

#include "Form.hpp"

class RobotomyRequestForm : public Form
{

  public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

  private:
	void exe(Bureaucrat const &performer) const;
};

#endif
