#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

class Enemy
{
  public:
	Enemy(Enemy const &src);
	Enemy(int hp, std::string const &type);
	virtual ~Enemy();
	Enemy &operator=(Enemy const &rhs);

	std::string getType() const;
	int getHP() const;

	virtual void takeDamage(int damage);

  protected:
	int hp;
	std::string type;
};

#endif
