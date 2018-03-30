#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>

class AWeapon
{

  private:
	std::string const name;
	int apcost;
	int damage;

  public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(AWeapon const &src);
	~AWeapon();
	std::string getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;

	AWeapon &operator=(AWeapon const &rhs);
};

#endif
