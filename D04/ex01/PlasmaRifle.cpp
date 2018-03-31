#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) : AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

//PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &rhs) {
//	this->AWeapon	
//}
