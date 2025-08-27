#pragma once
#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <string>
#include "../AForm/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

	std::string getName() const;
	int getGrade_sign() const;
	int getGrade_execute() const;
	int get_Signature() const;
	void beSigned(Bureaucrat &obj);

	void executeAction(Bureaucrat const &obj) const;

private:
	std::string _target;
	ShrubberyCreationForm();
};

#endif