/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no <no@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 23:42:42 by nboulaye          #+#    #+#             */
/*   Updated: 2018/04/01 09:38:29 by no               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_HPP
# define STAR_HPP

class star
{
	private:
		char	output;
		int		posX;
		int		posY;

	public:
	
		star( void );
		star( star const & src );
		virtual ~star( void );

		star &							operator=( star const & rhs );
	
};
std::ostream & operator<<(std::ostream & o, star const & rhs);

#endif
