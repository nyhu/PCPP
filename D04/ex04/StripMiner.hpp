#ifndef STRIPMINER_H
#define STRIPMINER_H

#include <iostream>
#include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser
{

  public:
	StripMiner(void);
	~StripMiner();

	StripMiner &operator=(StripMiner const &rhs);

	virtual void mine(IAsteroid *a);
};

#endif
