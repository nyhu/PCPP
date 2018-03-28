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
    Fixed & operator+(const Fixed &fixed);
    Fixed & operator-(const Fixed &fixed);
    Fixed & operator*(const Fixed &fixed);
    Fixed & operator/(const Fixed &fixed);

    Fixed & operator++();
    Fixed operator++(int);
    Fixed & operator--();
    Fixed operator--(int);

    bool operator>(const Fixed &fixed);
    bool operator>=(const Fixed &fixed);
    bool operator<(const Fixed &fixed);
    bool operator<=(const Fixed &fixed);
    bool operator==(const Fixed &fixed);
    bool operator!=(const Fixed &fixed);

    float toFloat(void) const;
    int toInt(void) const;

	int	getRawBits(void) const;
	void setRawBits(int const raw);

    static Fixed &min(Fixed &f1, Fixed &f2);
    static Fixed const &min(Fixed const &f1, Fixed const &f2);
    static Fixed &max(Fixed &f1, Fixed &f2);
    static Fixed const &max(Fixed const &f1, Fixed const &f2);

private:
	static const int _binary_point = 8;
	int	raw_value;

};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);


#endif
