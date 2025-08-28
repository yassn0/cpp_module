#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy._name, copy._grade_to_sign, copy._grade_to_exec), _target(copy._target)
{
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (this != &obj)
		_target = obj._target;
	return *this;
}

std::string PresidentialPardonForm::getName() const
{
	return _name;
}

int PresidentialPardonForm::getGrade_sign() const
{
	return _grade_to_sign;
}

int PresidentialPardonForm::getGrade_execute() const
{
	return _grade_to_exec;
}

int PresidentialPardonForm::get_Signature() const
{
	return _signed;
}

void PresidentialPardonForm::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() <= _grade_to_sign)
	{
		_signed = true;
		std::cout << obj.getName() << " signed " << _name << std::endl;
	}
	else
	{
		std::cout << obj.getName() << " couldn't sign " << _name << " because grade is too low"
			    << std::endl;
		throw PresidentialPardonForm::GradeTooLowException();
	}
}

void PresidentialPardonForm::executeAction(Bureaucrat const &) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}