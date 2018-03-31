#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy
{

  public:
	RadScorpion(RadScorpion const &src);
	RadScorpion();
	~RadScorpion();

	RadScorpion &operator=(RadScorpion const &rhs);
};

#endif
