#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "../Animal/Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(const Cat &);
	Cat &operator=(const Cat &);
	
	void	makeSound();

};

#endif