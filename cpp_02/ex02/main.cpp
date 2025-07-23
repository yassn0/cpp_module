#include "Fixed/Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	return 0;
	
	// Fixed a(1);
	// Fixed b(2);
	
	// std::cout << (b < a) << std::endl;
	// std::cout << (b > a) << std::endl;
	// std::cout << (b <= a) << std::endl;
	// std::cout << (b >= a) << std::endl;
	// std::cout << (b == a) << std::endl;
	// std::cout << (b != a) << std::endl;
	// std::cout <<  std::endl;
	
	// Fixed c = a + b;
	// std::cout <<  c << std::endl;
	// std::cout <<  a << std::endl;
}
