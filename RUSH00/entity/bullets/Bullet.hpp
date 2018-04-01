/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no <no@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 23:42:42 by nboulaye          #+#    #+#             */
/*   Updated: 2018/04/01 16:52:05 by no               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP
#include "BulletList.hpp"

class Bullet : public AShip
{
	public:
	
		Bullet( void );
		Bullet( Bullet const & src );
		virtual ~Bullet( void );
		Bullet(int pv, char ouput, int posX, int posY, int directionX, int directionY);
		virtual void respawn();


		Bullet &	operator=( Bullet const & rhs );
	
};

#endif
