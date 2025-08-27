#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>
#include "../Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(std::string name, int grade_sign, int grade_exec);
	~Form();
	Form(const Form &);
	Form &operator=(const Form &);

	std::string getName() const;
	int getGrade_sign() const;
	int getGrade_execute() const;
	int get_Signature() const;
	void	beSigned(Bureaucrat &obj);

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

private:
	const std::string _name;
	bool _signed;
	const int _grade_to_sign;
	const int _grade_to_exec;
	Form();
	Form(std::string name);
	Form(std::string name, int grade_sign);
	
	
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif