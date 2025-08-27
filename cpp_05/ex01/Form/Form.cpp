#include "Form.hpp"

static void grade_check(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

static std::string display_false_or_not(const Form &obj)
{
	if (obj.get_Signature())
		return " true ";
	else
		return " false ";
}

Form::Form(std::string name, int grade_sign, int grade_exec) : _name(name),_signed(false), _grade_to_sign(grade_sign), _grade_to_exec(grade_exec)
{
	grade_check(_grade_to_sign);
	grade_check(_grade_to_exec);
	std::cout << "Form Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(false), _grade_to_sign(copy._grade_to_sign), _grade_to_exec(copy._grade_to_exec)
{
	std::cout << "Form Copy Constructor called" << std::endl;
	*this = copy;
}

Form &Form::operator=(const Form &other)
{
	(void) other;
	std::cout << "Form operator= called" << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << obj.getName() << " form, state of signature: " << display_false_or_not(obj) << ","
	<< " grade required to sign the form: " << obj.getGrade_sign() << ","
	<< " grade required to execute the form: " << obj.getGrade_execute() << std::endl;
	return os;
}

std::string Form::getName() const
{
	return _name;
}

int Form::getGrade_sign() const
{
	return _grade_to_sign;
}

int Form::getGrade_execute() const
{
	return _grade_to_exec;
}

int Form::get_Signature() const
{
	return _signed;
}

void	Form::beSigned(Bureaucrat &obj)
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
		throw Form::GradeTooLowException();
	}
}
