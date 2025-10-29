#include <iostream>
#include <string>
#include "Bureaucrat/Bureaucrat.hpp"
#include "AForm/AForm.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"

int main()
{
	std::cout << "Test 1: ShrubberyCreationForm" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 100);
		ShrubberyCreationForm form("home");

		std::cout << "Signing form : " << std::endl;
		bob.signForm(form);
		std::cout << "Executing form : " << std::endl;
		bob.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Test 2: RobotomyRequestForm" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm robotForm("target");

		alice.signForm(robotForm);
		alice.executeForm(robotForm);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Test 3: PresidentialPardonForm" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardonForm("criminal");

		president.signForm(pardonForm);
		president.executeForm(pardonForm);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Test 4: Grade too low for execution" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm form("garden");

		intern.signForm(form);
		intern.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << "Expected error: " << e.what() << std::endl;
	}
	return 0;
}