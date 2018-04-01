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
