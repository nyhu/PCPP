#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "Form.hpp"

class PresidentialPardonForm : public Form {

public:

	PresidentialPardonForm( std::string const & target );
	PresidentialPardonForm( PresidentialPardonForm const & src );
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=( PresidentialPardonForm const & rhs );
private:
	virtual void exe(Bureaucrat const &b) const;
};

#endif
