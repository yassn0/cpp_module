#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
	std::cout << "= operator called" << std::endl;
	return *this;
}

Cat::Cat(const Cat &other)
{
	if (this != &other)
		*this = other;
	std::cout << "Copy Cat Constructor called" << std::endl;
	
}

void Cat::makeSound() const
{
	std::cout << "Cat Sound" << std::endl;
}

std::string Cat::getType() const
{
	return type;
}