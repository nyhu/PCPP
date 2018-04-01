/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no <no@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 23:42:42 by nboulaye          #+#    #+#             */
/*   Updated: 2018/04/01 15:17:45 by no               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bullet.hpp"

Bullet::Bullet ( void )
{
	return ;
}

Bullet::Bullet ( Bullet const & src )
{
	*this = src;
	return ;
}

Bullet::Bullet(int pv, char ouput, int posX, int posY, int directionX, int directionY)
{
this->pv = pv;
this->ouput = ouput;
this->posX = posX;
this->posY = posY;
this->directionX = directionX;
this->directionY = directionY;
this->frameSinceLastAttack = 0;
}

Bullet &				Bullet::operator=( Bullet const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Bullet::~Bullet ( void )
{
	return ;
}

// std::ostream &				operator<<(std::ostream & o;Bullet const & rhs)
// {
// 	(void)i;
// 	return (o);
// }


void Bullet::respawn()
{
 return ;
}