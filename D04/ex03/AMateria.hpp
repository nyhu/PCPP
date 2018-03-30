#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>

#include "ICharacter.hpp"

class AMateria
{

  public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	virtual ~AMateria();

	AMateria &operator=(AMateria const &rhs);

	std::string const &getType() const; //Returns the materia type
	unsigned int getXP() const;			//Returns the Materia's XP

	virtual AMateria *clone(void) const = 0;
	virtual void use(ICharacter &target);

  private:
	std::string type_;
	unsigned int xp_;
};

#endif
