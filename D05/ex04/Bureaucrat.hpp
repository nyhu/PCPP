#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <stdexcept>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
  Bureaucrat(std::string name, unsigned short grade);
  Bureaucrat(Bureaucrat const &b);
  ~Bureaucrat();

  Bureaucrat &operator=(Bureaucrat const &b);

  std::string getName() const;
  unsigned short getGrade() const;
  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return ("grade to hight");
    }
  };
  class GradeTooLowException : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return ("grade to low");
    }
  };

  void signForm(Form &f);
  void executeForm(Form const &f) const;

private:
  Bureaucrat();

  void validateGrade(unsigned short grade);

  const std::string name;
  unsigned short grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b);

#endif