#include "Character.hpp"

Character::Character(std::string const &name)
	: name(name), AP(40)
{
}

Character::Character(Character const &src)
	: name(src.name), AP(src.AP), weapon(src.weapon)
{
}

Character::~Character(void)
{
}

void Character::recoverAP()
{
	this->AP += 10;
	if (this->AP > 40)
		this->AP = 40;
}

void Character::equip(AWeapon *weapon)
{
	this->weapon = weapon;
}

void Character::attack(Enemy *target)
{
	if (!this->weapon || this->AP - this->weapon->getAPCost() < 0)
		return;
	else
		this->AP -= this->weapon->getAPCost();
	std::cout << this->name << " attacks " << target->getType() << " with a " << this->weapon->getName() << std::endl;
	this->weapon->attack();
	target->takeDamage(this->weapon->getDamage());
	if (target->getHP() < 0)
		delete target;
}

std::string Character::getName() const
{
	return this->name;
}

int Character::getAP() const
{
	return this->AP;
}

std::string Character::getWeapon() const
{
	if (this->weapon)
		return this->weapon->getName();
	else
		return "";
}

std::ostream &operator<<(std::ostream &o, Character const &i)
{
	if (i.getWeapon().compare("") == 0)
		o << i.getName() << " has " << i.getAP() << " AP and wields a " << i.getWeapon() << std::endl;
	else
		o << i.getName() << " has " << i.getAP() << " AP and is unarmed" << std::endl;

	return o;
}
