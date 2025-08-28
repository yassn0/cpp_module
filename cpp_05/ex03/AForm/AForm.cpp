#include "AForm.hpp"

static void grade_check(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
}

static std::string display_false_or_not(const AForm &obj)
{
	if (obj.get_Signature())
		return " true ";
	else
		return " false ";
}

AForm::AForm(std::string name, int grade_sign, int grade_exec) : _name(name), _signed(false), _grade_to_sign(grade_sign), _grade_to_exec(grade_exec)
{
	grade_check(_grade_to_sign);
	grade_check(_grade_to_exec);
}

AForm::~AForm()
{
}

void AForm::execute(Bureaucrat const &obj) const
{
	if (!this->get_Signature())
		throw ContractNotSigned();
	else if (obj.getGrade() > this->getGrade_execute())
		throw GradeTooLowException();
	this->executeAction(obj);
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << obj.getName() << " form, state of signature: " << display_false_or_not(obj) << ","
	   << " grade required to sign the form: " << obj.getGrade_sign() << ","
	   << " grade required to execute the form: " << obj.getGrade_execute() << std::endl;
	return os;
}
