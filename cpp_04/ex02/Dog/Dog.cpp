#include "Dog.hpp"

Dog::Dog() : _brain(new Brain())
{
	type = "Dog";
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
	std::cout << "= operator called" << std::endl;
	return *this;
}

Dog::Dog(const Dog &other)
{
	if (this != &other)
		*this = other;
	std::cout << "Copy Dog Constructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog Sound" << std::endl;
}

std::string Dog::getType() const
{
	return type;
}