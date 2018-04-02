#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(const std::string name, unsigned short grade) : name(name), grade(grade)
{
    validateGrade(grade);
}
Bureaucrat::Bureaucrat(Bureaucrat const &b) : name("John")
{
    *this = b;
}
Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &b)
{
    grade = b.grade;
    return *this;
}

std::string Bureaucrat::getName() const 
{
    return name;
}
unsigned short Bureaucrat::getGrade() const 
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    validateGrade(grade - 1);
    grade--;
}

void Bureaucrat::decrementGrade()
{
    validateGrade(grade + 1);
    grade++;
}

void Bureaucrat::validateGrade(unsigned short grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b)
{
    o << "<" << b.getName() << ">, bureacrate grade " << b.getGrade();
    return o;
}
