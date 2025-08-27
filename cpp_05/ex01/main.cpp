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
		Form contract("Contract", 50, 25);
		
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

	// std::cout << std::endl << "--- Test 4: Bureaucrat ne peut pas signer (grade trop bas) ---" << std::endl;
	// try
	// {
	// 	Bureaucrat intern("Intern", 100);
	// 	Form topSecret("Top Secret", 20, 10);
		
	// 	std::cout << intern << std::endl;
	// 	std::cout << topSecret << std::endl;
		
	// 	intern.signForm(topSecret);
	// 	std::cout << "Après tentative de signature:" << std::endl;
	// 	std::cout << topSecret << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }

	// std::cout << std::endl << "--- Test 5: Test de copie de Form ---" << std::endl;
	// try
	// {
	// 	Form original("Original", 50, 30);
	// 	Form copy = original;
		
	// 	std::cout << "Original: " << original << std::endl;
	// 	std::cout << "Copy: " << copy << std::endl;
		
	// 	Bureaucrat signer("Signer", 40);
	// 	signer.signForm(copy);
		
	// 	std::cout << "Après signature de la copie:" << std::endl;
	// 	std::cout << "Original: " << original << std::endl;
	// 	std::cout << "Copy: " << copy << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }

	return 0;
}