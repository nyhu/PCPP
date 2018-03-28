#include "Fixed.hpp"

Fixed::Fixed(void): raw_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n): raw_value(n << Fixed::_binary_point) {
	std::cout << "Int constructor called" << std::endl;	
}

Fixed::Fixed(float const f) : raw_value(roundf(f * (1 << Fixed::_binary_point))) {
	std::cout << "Float constructor called" << std::endl;
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

float Fixed::toFloat(void) const {
	return this->raw_value / (float)(1 << Fixed::_binary_point);
}

int Fixed::toInt(void) const {
	return this->raw_value >> Fixed::_binary_point;
}

int	Fixed::getRawBits(void) const {
	return this->raw_value;
}

void Fixed::setRawBits(int const raw) {
	this->raw_value = raw;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
	return o << i.toFloat();
}