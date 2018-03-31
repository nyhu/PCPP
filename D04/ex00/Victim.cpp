#include "Victim.hpp"

Victim::Victim(void)
	: name("Victor")
{
	std::cout << "Some random victim called " << this->name << " just popped !" << std::endl;
}

Victim::Victim(std::string name)
	: name(name)
{
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::Victim(Victim const &src)
	: name(src.getName())
{
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << name << " just died for no apparent reason !" << std::endl;
}

/*
** Features
*/

std::string const &Victim::getName() const
{
	return this->name;
}

void Victim::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream &operator<<(std::ostream &o, Victim const &i)
{
	o << "I'm " << i.getName() << " and I like otters !" << std::endl;

	return o;
}
