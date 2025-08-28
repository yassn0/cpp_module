#pragma once
#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <string>
#include "../AForm/AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);

	std::string getName() const;
	int getGrade_sign() const;
	int getGrade_execute() const;
	int get_Signature() const;
	void beSigned(Bureaucrat &obj);

	void executeAction(Bureaucrat const &obj) const;

private:
	std::string _target;
	RobotomyRequestForm();
};

#endif