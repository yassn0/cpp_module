#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("default")
{
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string typ) : type(typ)
{
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "= operator called" << std::endl;
	return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	if (this != &other)
		*this = other;
	std::cout << "Copy WrongAnimal Constructor called" << std::endl;
}

std::string WrongAnimal::getType()
{
	return type;
}

void WrongAnimal::makeSound()
{
	std::cout << "Aninal Sound" << std::endl;
}
