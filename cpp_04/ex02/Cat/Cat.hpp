#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "../AAnimal/AAnimal.hpp"
#include "../Brain/Brain.hpp"

class Cat : public AAnimal
{
public:
	Cat();
	~Cat();
	Cat(const Cat &);
	Cat &operator=(const Cat &);
	
	void	makeSound() const;
	std::string	getType() const;

private:
	Brain *_brain;
	
};

#endif