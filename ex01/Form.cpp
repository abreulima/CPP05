#include "Bureaucrat.hpp"
#include "Form.hpp"


Form::Form() : name("Form"), isSigned(false), gradeToSign(50),
	gradeToExecute(100)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name),
	isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	//std::cout << "Constructor" << std::endl;

	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
	else if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned),
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return (*this);
}

const std::string &Form::getName() const
{
	return (name);
}

int Form::getGradeToSign() const
{
	return (gradeToSign);
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

void Form::beSigned(Bureaucrat &b)
{
	if (gradeToSign >= b.getGrade())
	{
		isSigned = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

Form::~Form()
{

}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form: grade too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form: grade too high";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    std::string status;
    if (f.getIsSigned())
    {
        status = "signed.";
    }
    else 
    {
        status = "not signed";

    }

	os << f.getName() << " requires a " << f.getGradeToSign() << " grade to be signed "
		<< "and a " << f.getGradeToExecute() 
        << " grade to be execute, currently the form is " << status;

    return os;
}