#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int nb) : _value(0)
{
	std::cout << "Int constructor called" << std::endl;
	_value = nb << _raw_bits;
}

Fixed::Fixed(float nb) : _value(0)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(nb * 256);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return *this;
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_value / 256;
}

int Fixed::toInt(void) const
{
	return _value >> _raw_bits;
}
