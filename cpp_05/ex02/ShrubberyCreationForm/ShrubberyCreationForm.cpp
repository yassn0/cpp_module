#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy._name, copy._grade_to_sign, copy._grade_to_exec), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this != &obj)
		_target = obj._target;
	return *this;
}

std::string ShrubberyCreationForm::getName() const
{
	return _name;
}

int ShrubberyCreationForm::getGrade_sign() const
{
	return _grade_to_sign;
}

int ShrubberyCreationForm::getGrade_execute() const
{
	return _grade_to_exec;
}

int ShrubberyCreationForm::get_Signature() const
{
	return _signed;
}

void ShrubberyCreationForm::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() <= _grade_to_sign)
	{
		_signed = true;
		std::cout << obj.getName() << " signed " << _name << std::endl;
	}
	else
	{
		std::cout << obj.getName() << " couldn't sign " << _name << " beacause is too low"
			    << std::endl;
		throw ShrubberyCreationForm::GradeTooLowException();
	}
}

void ShrubberyCreationForm::executeAction(Bureaucrat const &) const
{
	const std::string str = _target + "_shrubbery";
	std::ofstream fd;
	fd.open(str.c_str());
	if (fd.fail())
	{
		fd.close();
		std::cout << "Error: Could not create file " << str << std::endl;
		return;
	}
	fd << "       *\n"
	   << "      /|\\\n"
	   << "     /*|O\\\n"
	   << "    /*/|\\*\\\n"
	   << "   /X/O|*\\X\\\n"
	   << "  /*/X/|\\X\\*\\\n"
	   << " /O/*/X|*\\O\\X\\\n"
	   << "/*/O/X/|\\X\\*\\O\\\n"
	   << "      |X|\n"
	   << "      |X|\n";
}
