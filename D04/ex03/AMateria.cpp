#include "AMateria.hpp"

AMateria::AMateria(void)
	: type_("default"), xp_(0)
{
}

AMateria::AMateria(std::string const &type)
	: type_(type), xp_(0)
{
}

AMateria::AMateria(AMateria const &src)
	: type_(src.getType()), xp_(0)
{
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(AMateria const &rhs)
{
	this->xp_ = rhs.getXP();

	return *this;
}

/*
** Features
*/

std::string const &AMateria::getType() const
{
	return this->type_;
}

unsigned int AMateria::getXP() const
{
	return this->xp_;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	this->xp_ += 10;
}
