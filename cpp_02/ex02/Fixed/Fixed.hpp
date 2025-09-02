#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed &other);

	Fixed &operator=(const Fixed &other);
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator*(const Fixed &other);
	Fixed operator/(const Fixed &other);
	Fixed operator++(int);
	Fixed operator--(int);
	Fixed &operator++();
	Fixed &operator--();

	~Fixed();

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);

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