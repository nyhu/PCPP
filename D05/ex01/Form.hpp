#ifndef __FORM__
#define __FORM__

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  public:
    Form(std::string name, unsigned short signGrade, unsigned short exeGrade);
    ~Form();

    Form &operator=(Form &f);

    class GradeTooHighException : std::exception
    {
    };
    class GradeTooLowException : std::exception
    {
    };

    unsigned short getSignGrade() const;
    unsigned short getExeGrade() const;
    std::string getName() const;
    bool isSigned() const;

    void beSigned(Bureaucrat &b);

  private:
    Form();
    Form(Form &f);

    void validateGrade(unsigned short grade);

    bool _signed;
    const std::string name;
    const unsigned short signGrade;
    const unsigned short exeGrade;
};

std::ostream &operator<<(std::ostream &o, Form const &f);

#endif