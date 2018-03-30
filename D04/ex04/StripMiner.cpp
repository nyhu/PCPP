#include "StripMiner.hpp"

StripMiner::StripMiner(void)
{
}

StripMiner::~StripMiner()
{
}

StripMiner &StripMiner::operator=(StripMiner const &rhs)
{
	(void)rhs;
	return *this;
}

void StripMiner::mine(IAsteroid *a)
{
	std::cout << "* strip mining ... got " << a->beMined(this) << " ! *" << std::endl;
}
