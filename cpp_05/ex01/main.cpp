#include <iostream>
#include <string>
#include "Bureaucrat/Bureaucrat.hpp"
#include "Form/Form.hpp"

int main()
{
	std::cout << "Test 1: Form valid" << std::endl;
	try
	{
		Form form1("Tax Form", 50, 25);
		std::cout << form1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "Test 2: Form grade invalid ---" << std::endl;
	try
	{
		Form form2("Invalid Form", 0, 25);
		std::cout << form2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "Test 3: Form grad invalid ---" << std::endl;
	try
	{
		Form form3("Invalid Form", 50, 151);
		std::cout << form3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Test 4: Bureaucrat sign Form" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 30);
		Form contract("Contract", 31, 25);
		
		std::cout << bob << std::endl;
		std::cout << contract << std::endl;
		
		bob.signForm(contract);
		std::cout << "After sign:" << std::endl;
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}