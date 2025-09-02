#include "Data.hpp"
#include <iostream>

Data::Data(std::string name) : _name(name)
{
	std::cout << "Data Constructor called" << std::endl;
}

Data::~Data()
{
	std::cout << "Data Destructor called" << std::endl;
}

Data::Data(const Data &copy) : _name(copy._name)
{
	std::cout << "Data Copy Constructor called" << std::endl;
}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
		_name = other._name;
	std::cout << "Data operator= called" << std::endl;
	return *this;
}