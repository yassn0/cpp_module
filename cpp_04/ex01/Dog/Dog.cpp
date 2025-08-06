#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	if (this != &other)
		Animal::operator=(other);
	std::cout << "= operator called" << std::endl;
	return *this;
}

Dog::Dog(const Dog &other) : Animal()
{
	if (this != &other)
		*this = other;
	std::cout << "Copy Dog Constructor called" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "Dog Sound" << std::endl;
}
