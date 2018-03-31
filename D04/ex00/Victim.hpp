#ifndef VICTIM_H
#define VICTIM_H

#include <iostream>

class Victim
{

public:
	Victim();
	Victim(std::string name);
	Victim(Victim const &src);
	~Victim();

	std::string const &getName(void) const;
	void getPolymorphed(void) const;

protected:
	std::string name;
};

std::ostream &operator<<(std::ostream &o, Victim const &i);

#endif
