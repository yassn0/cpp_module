#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::list<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	
	bool b = easyfind(v, 5);
	std::cout << std::boolalpha << b << std::endl;
}