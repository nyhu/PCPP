#ifndef PEON_H
#define PEON_H

#include "Victim.hpp"

class Peon : public Victim
{

public:
	Peon();
	Peon(std::string name);
	Peon(Peon const &p);
	~Peon();

	void getPolymorphed() const;
};

#endif
