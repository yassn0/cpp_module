#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "Intern Constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern &)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &)
{
	std::cout << "Intern operator= called" << std::endl;
	return *this;
}

static AForm *createRobotomyForm(std::string target)
{
	std::cout << "Intern creates RobotomyRequestForm" << std::endl;
	return new RobotomyRequestForm(target);
}

static AForm *createShrubberyForm(std::string target)
{
	std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
	return new ShrubberyCreationForm(target);
}

static AForm *createPresidentialForm(std::string target)
{
	std::cout << "Intern creates PresidentialPardonForm" << std::endl;
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	std::string form_names[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	AForm *(*form_creators[3])(std::string) = {createRobotomyForm, createShrubberyForm, createPresidentialForm};
	for (int i = 0; i < 3; i++)
	{
		if (!form_name.compare(form_names[i]))
			return form_creators[i](target);
	}
	std::cout << "Error: Valid forms -> robotomy request, shrubbery creation, presidential pardon" << std::endl;
	return NULL;
}
