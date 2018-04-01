/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no <no@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 23:42:42 by nboulaye          #+#    #+#             */
/*   Updated: 2018/04/01 09:41:46 by no               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "star.hpp"

star::star ( void )
{
	this->output = '*';
	this->posX = rand() % PLAYGROUND_W;
	this->posY = rand() % PLAYGROUND_H;
	return ;
}

star::star ( star const & src )
{
	*this = src;
	return ;
}

star &				star::operator=( star const & rhs )
{
	if (this != &rhs)
	{
		this->output = rhs->output;
		this->posX = rhs->posX;
		this->posY = rhs->posY;
	}
	return (*this);
}

star::~star ( void )
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, star const & rhs)
{
	(void)i;
	return (o);
}


