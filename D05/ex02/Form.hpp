#ifndef __FORM__
#define __FORM__

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
  Form(std::string name, unsigned short signGrade, unsigned short exeGrade, std::string target);
  Form(Form const &f);
  ~Form();

  Form &operator=(Form &f);

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
  class NotSignedException : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return ("contract not signed before execution");
    }
  };

  std::string getTarget() const;
  unsigned short getSignGrade() const;
  unsigned short getExeGrade() const;
  std::string getName() const;
  bool isSigned() const;

  void beSigned(Bureaucrat &b);
  void execute(Bureaucrat const &b) const;

private:
  Form();

  virtual void exe(Bureaucrat const &b) const = 0;
  void validateGrade(unsigned short grade);

  bool _signed;
  const std::string name;
  const unsigned short signGrade;
  const unsigned short exeGrade;
  std::string target;
};

std::ostream &operator<<(std::ostream &o, Form const &f);

#endif