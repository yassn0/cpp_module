#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "../AAnimal/AAnimal.hpp"
#include "../Brain/Brain.hpp"

class Dog : public AAnimal
{
public:
	Dog();
	~Dog();
	Dog(const Dog &);
	Dog &operator=(const Dog &);
	
	void	makeSound() const;
	std::string	getType() const;
	
private:
	Brain *_brain;

};

#endif