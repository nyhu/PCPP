#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const &src) : AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
}

PowerFist::~PowerFist(void)
{
}

void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
