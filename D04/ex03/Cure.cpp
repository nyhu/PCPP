#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(Cure const &src) : AMateria(src)
{
}

Cure::~Cure()
{
}

/*
** Features
*/

AMateria *Cure::clone(void) const
{
	AMateria *clone = new Cure();

	return clone;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
