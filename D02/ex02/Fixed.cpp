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

Fixed &	Fixed::operator+(Fixed const & rhs) {
	std::cout << "Addition operator called" << std::endl;
	this->raw_value += rhs.getRawBits();

	return *this;
}

Fixed &	Fixed::operator-(Fixed const & rhs) {
	std::cout << "Substitution operator called" << std::endl;
	this->raw_value -= rhs.getRawBits();

	return *this;
}

Fixed &	Fixed::operator*(Fixed const & rhs) {
	std::cout << "Multiplication operator called" << std::endl;
	this->raw_value *= rhs.getRawBits();

	return *this;
}

Fixed &	Fixed::operator/(Fixed const & rhs) {
	std::cout << "Division operator called" << std::endl;
	this->raw_value /= rhs.getRawBits();

	return *this;
}

Fixed &	Fixed::operator++() {
	std::cout << "Prefix increment operator called" << std::endl;
	this->raw_value += (1 << Fixed::_binary_point);

	return *this;
}

Fixed Fixed::operator++(int) {
	std::cout << "Postfix increment operator called" << std::endl;
    Fixed tmp = *this;
	this->raw_value += (1 << Fixed::_binary_point);
    
	return tmp;
}

Fixed &	Fixed::operator--() {
	std::cout << "Prefix decrement operator called" << std::endl;
	this->raw_value -= (1 << Fixed::_binary_point);

	return *this;
}

Fixed Fixed::operator--(int) {
	std::cout << "Postfix decrement operator called" << std::endl;
    Fixed tmp = *this;
	this->raw_value -= (1 << Fixed::_binary_point);
    
	return tmp;
}

bool Fixed::operator>(const Fixed &fixed) {
    return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) {
    return this->getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) {
    return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) {
    return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) {
    return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) {
    return this->getRawBits() != fixed.getRawBits();
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

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    if (f1 > f2) {
        return f2;
    }
    return f1;
}

Fixed const &Fixed::min(const Fixed &f1, const Fixed &f2) {
    if (f1.getRawBits() > f2.getRawBits()) {
        return f2;
    }
    return f1;
}


Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    if (f1 > f2) {
        return f1;
    }
    return f2;
}

Fixed const &Fixed::max(const Fixed &f1, const Fixed &f2) {
    if (f1.getRawBits() > f2.getRawBits()) {
        return f1;
    }
    return f2;
}