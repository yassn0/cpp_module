#include <iostream>
#include <string>
#include "Bureaucrat/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Bob", 2);
		Bureaucrat b = a;

		std::cout << std::endl
			    << a << std::endl;

		std::cout << b << std::endl;
		
		a.grade_minus();
		a.grade_minus();
		std::cout << a << std::endl;
		
		
		
		
	}
	catch (std::exception &e)
	{
		std::cout << "grade error" << std::endl;
	}
}