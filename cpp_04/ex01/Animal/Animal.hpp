#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
public:
	Animal();
	Animal(std::string typ);
	virtual ~Animal();
	Animal(const Animal &);
	virtual Animal &operator=(const Animal &);

	std::string getType();
	virtual void	makeSound();

protected:
	std::string type;
};

#endif