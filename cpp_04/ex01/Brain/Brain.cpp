#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	
	std::cout << "= operator called" << std::endl;
	return *this;
}

Brain::Brain(const Brain &copy)
{
	if (this != &copy)
		*this = copy;
	std::cout << "Copy Brain Constructor called" << std::endl;
}