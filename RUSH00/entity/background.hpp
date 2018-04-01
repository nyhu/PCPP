/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no <no@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 23:42:42 by nboulaye          #+#    #+#             */
/*   Updated: 2018/04/01 10:15:09 by no               ###   ########.fr       */
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

		void computePlayfield(t_playfield &p);
		void move();		
		background & operator=( background const & rhs );
	
};
// std::ostream & operator<<(std::ostream & o, background const & rhs);

#endif
