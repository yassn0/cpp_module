#pragma once
#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
public:
	virtual ~AAnimal() {};

	virtual std::string getType() const = 0;
	virtual void	makeSound() const = 0;

protected:
	std::string type;
};

#endif