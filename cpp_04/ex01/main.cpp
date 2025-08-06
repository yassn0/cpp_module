#include <iostream>
#include <string>
#include "Animal/Animal.hpp"
#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"
#include "Brain/Brain.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j; // should not create a leak
	delete i;
	Animal *tab[4] = {new Dog(),new Dog(), new Cat(), new Cat()};
	for (int i = 0; i < 4; i++)
	{
		delete tab[i];
	}
	return 0;
}