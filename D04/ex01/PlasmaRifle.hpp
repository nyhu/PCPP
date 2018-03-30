#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{

  public:
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const &src);
	~PlasmaRifle(void);
	virtual void attack(void) const;

	PlasmaRifle &operator=(PlasmaRifle const &rhs);
};

#endif
