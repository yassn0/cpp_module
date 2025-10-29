#include <iostream>
#include <string>
#include "Bureaucrat/Bureaucrat.hpp"
#include "AForm/AForm.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Intern/Intern.hpp"

int main()
{
	Bureaucrat b1("bob", 1);
	
	Intern someRandomIntern;
	AForm *rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (!rrf)
		return 1;
	rrf->beSigned(b1);
	rrf->execute(b1);
	delete rrf;
	return 0;
}