/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no <no@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 23:42:42 by nboulaye          #+#    #+#             */
/*   Updated: 2018/04/01 17:35:12 by no               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_HPP
# define BACKGROUND_HPP

#include "ships/AShip.hpp"


class background
{
	private:
		AShip 	**star;
		int		nb_star;

	public:
		background( void );
		background( background const & src );
		virtual ~background( void );
		background & operator=( background const & rhs );
		void computePlayfield(t_playfield &p);
		void move();		
	
};
#endif
