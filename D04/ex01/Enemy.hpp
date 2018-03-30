#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

class Enemy
{

  protected:
	int hp;
	std::string const &type;

  public:
	Enemy(Enemy const &src);
	Enemy(int hp, std::string const &type);
	virtual ~Enemy(void);
	std::string getType(void) const;
	int getHP(void) const;

	virtual void takeDamage(int damage);

	Enemy &operator=(Enemy const &rhs);
};

#endif
