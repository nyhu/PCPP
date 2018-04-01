/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no <no@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 23:42:42 by nboulaye          #+#    #+#             */
/*   Updated: 2018/04/01 11:01:41 by no               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "background.hpp"

background::background ( void )
{
	int i = -1;

	this->nb_star = 42;
	this->star = new AShip*[this->nb_star];
	while(++i < this->nb_star)
	{
		this->star[i] = new AShip(0, '*', rand() % PLAYGROUND_W, rand() % PLAYGROUND_H, 1, 0);
	}
	return ;
}

background::background ( background const & src )
{
	*this = src;
	return ;
}

background &				background::operator=( background const & rhs )
{
	if (this != &rhs)
	{
	}
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
	return ;
}

void	background::move()
{
	int i = -1;


	while(++i < this->nb_star)
	{
		if (this->star[i]->getPosX() > 1)
			this->star[i]->setPosition(this->star[i]->getPosX() - 1, this->star[i]->getPosY());
		else
			this->star[i]->setPosition(PLAYGROUND_W - 1, this->star[i]->getPosY());

	}
	return ;
}



// std::ostream &				operator<<(std::ostream & o, background const & rhs)
// {
// 	(void)i;
// 	return (o);
// }


