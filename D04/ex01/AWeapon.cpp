#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
	: name(name), apcost(apcost), damage(damage)
{
}

AWeapon::AWeapon(AWeapon const &src)
	: name(src.name), apcost(src.apcost), damage(src.damage)
{
}

AWeapon::~AWeapon()
{
}

std::string AWeapon::getName() const
{
	return this->name;
}

int AWeapon::getAPCost() const
{
	return this->apcost;
}

int AWeapon::getDamage() const
{
	return this->damage;
}
