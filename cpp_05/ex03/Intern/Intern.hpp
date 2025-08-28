#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "../AForm/AForm.hpp"
#include "../ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../PresidentialPardonForm/PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &);
	Intern &operator=(const Intern &);
	AForm *makeForm(std::string form_name, std::string target);

private:
};

#endif