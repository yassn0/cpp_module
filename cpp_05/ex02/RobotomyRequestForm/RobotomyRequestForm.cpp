#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy._name, copy._grade_to_sign, copy._grade_to_exec), _target(copy._target)
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this != &obj)
		_target = obj._target;
	return *this;
}

std::string RobotomyRequestForm::getName() const
{
	return _name;
}

int RobotomyRequestForm::getGrade_sign() const
{
	return _grade_to_sign;
}

int RobotomyRequestForm::getGrade_execute() const
{
	return _grade_to_exec;
}

int RobotomyRequestForm::get_Signature() const
{
	return _signed;
}

void RobotomyRequestForm::beSigned(Bureaucrat &obj)
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
		throw RobotomyRequestForm::GradeTooLowException();
	}
}

void RobotomyRequestForm::executeAction(Bureaucrat const &) const
{
	std::cout << "* DRILLING NOISES *" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
	{
		std::cout << "The robotomy failed for " << _target << std::endl;
	}
}
