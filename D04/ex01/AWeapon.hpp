#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>

class AWeapon
{
  public:
	AWeapon();
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(AWeapon const &src);
	virtual ~AWeapon();
	std::string getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;

	// AWeapon &operator=(AWeapon const &w);

  private:
	std::string name;
	int apcost;
	int damage;
};

#endif
