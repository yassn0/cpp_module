#include "Animal.hpp"

Animal::Animal() : type("default")
{
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(std::string typ) : type(typ)
{
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this == &other)
		return *this;
	if (this != &other)
		this->type = other.type;
	std::cout << "= operator called" << std::endl;
	return *this;
}

Animal::Animal(const Animal &other)
{
	if (this != &other)
		*this = other;
	std::cout << "Copy Animal Constructor called" << std::endl;
}

std::string Animal::getType()
{
	return type;
}

void Animal::makeSound()
{
	std::cout << "Aninal Sound" << std::endl;
}
