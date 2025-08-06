#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include <iostream>
#include "../WrongAnimal/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &);
	WrongCat &operator=(const WrongCat &);
	
	void	makeSound();

};

#endif