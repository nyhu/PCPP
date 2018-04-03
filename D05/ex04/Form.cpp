#include "Form.hpp"

Form::Form()
    : _signed(false), name(""), signGrade(0), exeGrade(0), target("")
{
    validateGrade(signGrade);
    validateGrade(exeGrade);
}

Form::Form(Form const &f)
    : _signed(f._signed), name(f.name), signGrade(f.signGrade), exeGrade(f.exeGrade), target(f.target) {}
Form::Form(std::string name, unsigned short signGrade, unsigned short exeGrade, std::string target)
    : _signed(false), name(name), signGrade(signGrade), exeGrade(exeGrade), target(target)
{
    validateGrade(signGrade);
    validateGrade(exeGrade);
}

Form::~Form() {}

Form &Form::operator=(Form &f)
{
    this->_signed = f._signed;
    this->target = f.target;
    return *this;
}

std::string Form::getTarget() const
{
    return target;
}

unsigned short Form::getSignGrade() const
{
    return signGrade;
}

unsigned short Form::getExeGrade() const
{
    return exeGrade;
}

std::string Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return _signed;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > signGrade)
        throw Form::GradeTooLowException();
    _signed = true;
}

void Form::execute(Bureaucrat const &b) const
{
    if (b.getGrade() > exeGrade)
        throw Form::GradeTooLowException();
    if (!_signed)
        throw Form::NotSignedException();
    exe(b);
}

void Form::validateGrade(unsigned short grade)
{
    if (grade > 150)
        throw Form::GradeTooLowException();
    if (grade < 1)
        throw Form::GradeTooHighException();
}

std::ostream &operator<<(std::ostream &o, Form const &f)
{
    o << "<" << f.getName() << ">, form sign grade " << f.getSignGrade() << ", execution grade " << f.getExeGrade();
    return o;
}
