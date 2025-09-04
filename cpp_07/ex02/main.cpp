#include <iostream>
#include "Array.hpp"
#include <exception>
#include <iostream>

int main()
{

	std::cout << "-- Test 1 --" << std::endl;
	Array<int> a(5);
	a[0] = 1;
	std::cout << "a[0] : " << a[0] << std::endl;
	std::cout << "Size a :" << a.size() << std::endl;

	std::cout << std::endl
		    << "-- Test 2 --" << std::endl;
	Array<int> b;
	std::cout << "Size b :" << b.size() << std::endl;

	try
	{
		std::cout << std::endl
			    << "-- Test 3 --" << std::endl;
		Array<int> a(1);

		std::cout << a[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl
			    << "-- Test 4 --" << std::endl;
		Array<int> a(1);

		std::cout << a[1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl
		    << "-- Test 5 --" << std::endl;
	Array<int> copy_a(a);
	std::cout << "Size copy_a : " << copy_a.size() << std::endl;
	std::cout << "copy_a[0] : " << copy_a[0] << std::endl;

	std::cout << std::endl
		    << "-- Test 6 --" << std::endl;
	Array<int> egal_a;
	egal_a = a;
	std::cout << "Size egal_a : " << egal_a.size() << std::endl;
	std::cout << "egal_a[0] : " << egal_a[0] << std::endl;
}