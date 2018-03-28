#ifndef __FIXED__
#define __FIXED__

#include <iostream>
#include <cmath>

class Fixed {
public:
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed &fixed);
    ~Fixed();

    Fixed & operator=(const Fixed &fixed);

    float toFloat(void) const;
    int toInt(void) const;

	int	getRawBits(void) const;
	void setRawBits(int const raw);

private:
	static const int _binary_point = 8;
	int	raw_value;

};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif