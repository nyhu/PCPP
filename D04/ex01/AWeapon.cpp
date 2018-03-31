#include "AWeapon.hpp"

AWeapon::AWeapon() : name("Bear hands"), apcost(1), damage(5)
{
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
	: name(name), apcost(apcost), damage(damage)
{
}

AWeapon::AWeapon(AWeapon const &src)
{
	*this = src;
}

AWeapon::~AWeapon()
{
}

// AWeapon &AWeapon::operator=(AWeapon const &w) {
// 	this->name = w.name;
// 	this->apcost = w.apcost;
// 	this->damage = w.damage;
// 	return *this;
// }

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
