#ifndef IMININGLASER_H
#define IMININGLASER_H

#include "IAsteroid.hpp"

class IMiningLaser
{

  public:
	virtual ~IMiningLaser() {}
	virtual void mine(IAsteroid *) = 0;
};

#endif
