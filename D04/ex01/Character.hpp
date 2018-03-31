#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
  private:
	std::string name;
	int AP;
	AWeapon *weapon;

  public:
	Character(Character const &src);
	Character(std::string const &name);
	~Character(void);
	void recoverAP();
	void equip(AWeapon *);
	void attack(Enemy *);
	std::string getName() const;
	int getAP() const;
	std::string getWeapon() const;

	Character &operator=(Character const &rhs);
};

std::ostream &operator<<(std::ostream &o, Character const &i);

#endif
