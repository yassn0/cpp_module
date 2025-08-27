#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>
#include "../Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm(std::string name, int grade_sign, int grade_exec);
	virtual ~AForm() = 0;

	virtual std::string getName() const = 0;
	virtual int getGrade_sign() const = 0;
	virtual int getGrade_execute() const = 0;
	virtual int get_Signature() const = 0;
	virtual void beSigned(Bureaucrat &obj) = 0;

	void execute(Bureaucrat const &obj) const;

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Grade must be between 1 and 150 !";
		}
	};
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Grade must be between 1 and 150 !";
		}
	};
	class ContractNotSigned : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Contract have to be signed for execute it";
		}
	};

private:
	AForm();
	AForm(std::string name);
	AForm(std::string name, int grade_sign);

protected:
	virtual void executeAction(Bureaucrat const &obj) const = 0;
	const std::string _name;
	bool _signed;
	const int _grade_to_sign;
	const int _grade_to_exec;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif