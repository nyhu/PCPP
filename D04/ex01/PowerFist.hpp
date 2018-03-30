#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{

  public:
	PowerFist(PowerFist const &src);
	PowerFist(void);
	~PowerFist(void);
	virtual void attack(void) const;

	PowerFist &operator=(PowerFist const &rhs);
};

#endif
