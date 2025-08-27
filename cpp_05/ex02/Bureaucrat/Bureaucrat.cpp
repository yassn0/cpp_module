#include "Bureaucrat.hpp"

static void grade_check(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	grade_check(_grade);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	std::cout << "Bureaucrat operator= called" << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << " , bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return os;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::grade_minus(void)
{
	try
	{
		grade_check(_grade - 1);
		_grade--;
	}
	catch (std::exception &e)
	{
		std::cout << "You cannot decrement under 1" << std::endl;
	}
}

void Bureaucrat::grade_plus(void)
{
	try
	{
		grade_check(_grade + 1);
		_grade++;
	}
	catch (std::exception &e)
	{
		std::cout << "You cannot decrement above 150" << std::endl;
	}
}

void Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't execute " << form.getName()
			    << " because " << e.what() << std::endl;
	}
}
