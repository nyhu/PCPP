#ifndef DEEPCOREMINER_H
#define DEEPCOREMINER_H

#include <iostream>
#include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser
{

  public:
	DeepCoreMiner(void);
	~DeepCoreMiner();

	DeepCoreMiner &operator=(DeepCoreMiner const &rhs);

	virtual void mine(IAsteroid *a);
};

#endif
