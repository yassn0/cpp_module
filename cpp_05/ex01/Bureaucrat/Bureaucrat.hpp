#pragma once
#ifndef BUREACUCRAT_HPP
#define BUREACUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include "../Form/Form.hpp"

class Form;

class Bureaucrat
{
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &);
	Bureaucrat &operator=(const Bureaucrat &);

	std::string getName() const;
	int getGrade() const;
	void grade_minus(void);
	void grade_plus(void);
	
	void	signForm(Form &form);

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Grade Too low";
		}
	};
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Grade Too high";
		}
	};

private:
	std::string const _name;
	int _grade;

	Bureaucrat();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif