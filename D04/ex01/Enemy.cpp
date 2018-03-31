#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type)
	: hp(hp), type(type)
{
}

Enemy::Enemy(Enemy const &src)
	: hp(src.hp), type(src.type)
{
}

Enemy::~Enemy()
{
}

std::string Enemy::getType() const
{
	return this->type;
}

int Enemy::getHP() const
{
	return this->hp;
}

void Enemy::takeDamage(int damage)
{
	if (damage > 0)
	{
		this->hp -= damage;
	}
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}
