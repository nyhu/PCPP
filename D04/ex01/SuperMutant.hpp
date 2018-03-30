#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{

  public:
	SuperMutant(SuperMutant const &src);
	SuperMutant(void);
	~SuperMutant(void);
	void takeDamage(int damage);

	SuperMutant &operator=(SuperMutant const &rhs);
};

#endif
