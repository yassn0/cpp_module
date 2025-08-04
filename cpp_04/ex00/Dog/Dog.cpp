#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "= operator called" << std::endl;
	return *this;
}

Dog::Dog(const Dog &other)
{
	if (this != &other)
		*this = other;
	std::cout << "Copy Dog Constructor called" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "Dog Sound" << std::endl;
}
