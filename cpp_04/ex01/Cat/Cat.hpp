#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "../Animal/Animal.hpp"
#include "../Brain/Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(const Cat &);
	Cat &operator=(const Cat &);
	
	void	makeSound();

private:
	Brain *_brain;
};

#endif