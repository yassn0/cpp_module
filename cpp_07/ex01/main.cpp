#include "iter.hpp"
#include <iostream>
#include <string>

void print(int a)
{
	std::cout << a << " ";
}

void increment(int &a)
{
	a++;
}

template<typename T>
void printTemplate(const T &value)
{
	std::cout << value << " ";
}

int main()
{
	int tab[5] = {1, 2, 3, 4, 5};
	std::cout << "Before: ";
	iter(tab, 5, print);
	std::cout << std::endl;

	iter(tab, 5, increment);
	std::cout << "After increment: ";
	iter(tab, 5, print);
	std::cout << std::endl;

	const int constTab[3] = {10, 20, 30};
	iter(constTab, 3, printTemplate<int>);
	std::cout << std::endl;

	std::string words[2] = {"Hello", "World"};
	iter(words, 2, printTemplate<std::string>);
	std::cout << std::endl;

	return 0;
}