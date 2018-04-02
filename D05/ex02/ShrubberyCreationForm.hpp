#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{

  public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	class CannotOpenException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return ("impossible to open file");
		}
	};

  private:
	void exe(Bureaucrat const &performer) const;
};

#endif
