#ifndef ASTEROBOCAL_H
#define ASTEROBOCAL_H

#include <iostream>
#include "IAsteroid.hpp"

class AsteroBocal : public IAsteroid
{

  public:
	AsteroBocal(void);
	AsteroBocal(AsteroBocal const &src);
	~AsteroBocal();

	AsteroBocal &operator=(AsteroBocal const &rhs);

	std::string getName() const;

	virtual std::string beMined(DeepCoreMiner *) const;
	virtual std::string beMined(StripMiner *) const;

  private:
	std::string name;
};

#endif
