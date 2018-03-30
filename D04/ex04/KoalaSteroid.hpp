#ifndef BOCALSTEROIDS_H
#define BOCALSTEROIDS_H

#include <iostream>
#include "IAsteroid.hpp"

class BocalSteroid : public IAsteroid
{

  public:
	BocalSteroid(void);
	BocalSteroid(BocalSteroid const &src);
	~BocalSteroid();

	BocalSteroid &operator=(BocalSteroid const &rhs);

	std::string getName() const;

	virtual std::string beMined(DeepCoreMiner *) const;
	virtual std::string beMined(StripMiner *) const;

  private:
	std::string name;
};

#endif
