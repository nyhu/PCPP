#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria
{

  public:
	Ice(void);
	Ice(Ice const &src);
	~Ice();

	AMateria *clone(void) const;
	void use(ICharacter &target);
};

#endif
