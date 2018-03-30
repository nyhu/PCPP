#ifndef SORCERER_H
#define SORCERER_H

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{

public:
	Sorcerer();
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const &src);
	~Sorcerer();

	Sorcerer &operator=(Sorcerer const &rhs);

	std::string const &getName(void) const;
	std::string const &getTitle(void) const;
	void polymorph(Victim const &victim) const;

private:
	std::string name;
	std::string title;
};

std::ostream &operator<<(std::ostream &o, Sorcerer const &i);

#endif
