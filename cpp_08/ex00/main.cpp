#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(3);
	lst.push_back(2);
	lst.push_back(5);
	lst.push_back(4);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 5);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Element not found" << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(lst, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Element not found" << std::endl;
	}
}