#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
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
	if (this != &other)
		Animal::operator=(other);
	std::cout << "= operator called" << std::endl;
	return *this;
}

Cat::Cat(const Cat &other) : Animal()
{
	if (this != &other)
		*this = other;
	std::cout << "Copy Cat Constructor called" << std::endl;
	
}

void Cat::makeSound()
{
	std::cout << "Cat Sound" << std::endl;
}
