#pragma once
#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <string>
#include "../AForm/AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);

	std::string getName() const;
	int getGrade_sign() const;
	int getGrade_execute() const;
	int get_Signature() const;
	void beSigned(Bureaucrat &obj);

	void executeAction(Bureaucrat const &) const;

private:
	std::string _target;
	PresidentialPardonForm();
};

#endif