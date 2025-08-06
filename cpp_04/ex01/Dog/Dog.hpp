#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "../Animal/Animal.hpp"
#include "../Brain/Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog &);
	Dog &operator=(const Dog &);
	
	void	makeSound();
	
private:
	Brain *_brain;

};

#endif