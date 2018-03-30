#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner(void)
{
}

DeepCoreMiner::~DeepCoreMiner()
{
}

DeepCoreMiner &DeepCoreMiner::operator=(DeepCoreMiner const &rhs)
{
	(void)rhs;
	return *this;
}

void DeepCoreMiner::mine(IAsteroid *a)
{
	std::cout << "* mining deep ... got " << a->beMined(this) << " ! *" << std::endl;
}
