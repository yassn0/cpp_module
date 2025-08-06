#pragma once
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string typ);
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &);
	virtual WrongAnimal &operator=(const WrongAnimal &);

	std::string getType();
	void	makeSound();

protected:
	std::string type;
};

#endif