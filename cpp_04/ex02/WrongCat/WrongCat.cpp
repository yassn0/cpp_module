#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this == &other)
		return *this;
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "= operator called" << std::endl;
	return *this;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
	if (this != &other)
		*this = other;
	std::cout << "Copy WrongCat Constructor called" << std::endl;
}

void WrongCat::makeSound()
{
	std::cout << "WrongCat Sound" << std::endl;
}
