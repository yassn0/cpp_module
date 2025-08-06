#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "= operator called" << std::endl;
	return *this;
}

Cat::Cat(const Cat &copy) : Animal()
{
	if (this != &copy)
		*this = copy;
	std::cout << "Copy Cat Constructor called" << std::endl;
	
}

void Cat::makeSound()
{
	std::cout << "Cat Sound" << std::endl;
}
