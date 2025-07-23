#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(int nb) : _value(0)
{
	_value = nb << _raw_bits;
}

Fixed::Fixed(float nb) : _value(0)
{
	this->_value = roundf(nb * 256);
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
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
}

int Fixed::getRawBits(void) const
{
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

bool Fixed::operator<(const Fixed &other)
{
	if (this->_value < other._value)
		return true;
	return false;
}

bool Fixed::operator>(const Fixed &other)
{
	if (this->_value > other._value)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &other)
{
	if (this->_value <= other._value)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &other)
{
	if (this->_value >= other._value)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &other)
{
	if (this->_value == other._value)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &other)
{
	if (this->_value != other._value)
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed &other)
{
	float nb = this->toFloat() + other.toFloat();

	return Fixed(nb);
}

Fixed Fixed::operator-(const Fixed &other)
{
	float nb = this->toFloat() - other.toFloat();

	return Fixed(nb);
}

Fixed Fixed::operator*(const Fixed &other)
{
	float nb = this->toFloat() * other.toFloat();

	return Fixed(nb);
}

Fixed Fixed::operator/(const Fixed &other)
{
	float nb = this->toFloat() / other.toFloat();

	return Fixed(nb);
}

Fixed Fixed::operator++(int)
{
	Fixed cpy(*this);

	this->_value++;
	return cpy;
}

Fixed Fixed::operator--(int)
{
	Fixed cpy(*this);

	this->_value--;
	return cpy;
}

Fixed &Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed &Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	else
		return b;
}