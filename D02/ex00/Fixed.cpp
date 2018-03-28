#include "Fixed.hpp"

Fixed::Fixed(void): raw_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n): raw_value(n) {
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;

	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->raw_value = rhs.getRawBits();

	return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw_value;
}

void Fixed::setRawBits(int const raw) {
	this->raw_value = raw;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
	o << i.getRawBits();

	return o;
}