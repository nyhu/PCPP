#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ) : Form("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : Form(src) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	((Form &)*this) = (Form &)rhs;
	return *this;
}

void PresidentialPardonForm::exe( Bureaucrat const & performer ) const
{
	(void)performer;
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

