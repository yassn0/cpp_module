#include <iostream>
#include <string>
#include "Bureaucrat/Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Bob", 2);
	Bureaucrat b("Bob2", 3);
	Bureaucrat c = a;
	
	std::cout << c.getName() << std::endl;
	std::cout << c.getGrade() << std::endl;
	
}