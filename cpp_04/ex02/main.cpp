#include <iostream>
#include <string>
#include "AAnimal/AAnimal.hpp"
#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"
#include "Brain/Brain.hpp"

int main()
{
	// const AAnimal a;
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();
	j->makeSound();
	i->makeSound();
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	delete j;
	delete i;
	return 0;
}