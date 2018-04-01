/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no <no@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 23:42:42 by nboulaye          #+#    #+#             */
/*   Updated: 2018/04/01 15:39:41 by no               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP
#include "../ships/AShip.hpp"
#include "../ships/IShip.hpp"

class Bullet : public AShip
{
	public:
	
		Bullet( void );
		Bullet( Bullet const & src );
		virtual ~Bullet( void );
		Bullet(int pv, char ouput, int posX, int posY, int directionX, int directionY);
		virtual void respawn();


		Bullet &							operator=( Bullet const & rhs );
	
};
// std::ostream & operator<<(std::ostream & o, Bullet const & rhs);

#endif
