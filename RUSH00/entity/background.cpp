#include "background.hpp"

background::background ( void )
{
	int i = -1;

	this->nb_star = 42;
	this->star = new AShip*[this->nb_star];
	while(++i < this->nb_star)
	{
		this->star[i] = new AShip(0, '*', rand() % PLAYGROUND_W, rand() % PLAYGROUND_H, -1, 0);
	}
	return ;
}

background::background ( background const & src )
{
	*this = src;
	return ;
}

background &	background::operator=( background const & rhs )
{
	this->nb_star = rhs.nb_star;
	this->star = rhs.star;
	return (*this);
}

background::~background ( void )
{
	int i = -1;

	while(++i < this->nb_star)
		delete this->star[i];
	delete this->star;
	return ;
}

void	background::computePlayfield(t_playfield &p)
{
	int i = -1;

	while(++i < this->nb_star)
		p[this->star[i]->getPosY()][this->star[i]->getPosX()] = this->star[i]->getOutput();
}

void	background::move()
{
	for(int i = 0;i < this->nb_star; i++)
		this->star[i]->move();
}
