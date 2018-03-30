#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(Ice const &src) : AMateria(src)
{
}

Ice::~Ice()
{
}

/*
** Features
*/

AMateria *Ice::clone(void) const
{
	AMateria *clone = new Ice();

	return clone;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
