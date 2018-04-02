#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <stdexcept>
#include <iostream>

class Bureaucrat
{
  public:
    Bureaucrat(std::string name, unsigned short grade);
    ~Bureaucrat();

    Bureaucrat &operator=(Bureaucrat const &b);

    std::string getName() const;
    unsigned short getGrade() const;
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : std::exception
    {
    };

    class GradeTooLowException : std::exception
    {
    };

  private:
    Bureaucrat();
    Bureaucrat(Bureaucrat const &b);

    void validateGrade(unsigned short grade);

    const std::string name;
    unsigned short grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b);

#endif