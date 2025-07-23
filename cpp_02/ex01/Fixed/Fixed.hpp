#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed &other);
	
	Fixed &operator=(const Fixed &other);
	
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _value;
	const static int _raw_bits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif