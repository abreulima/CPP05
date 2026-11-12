#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default
AForm::AForm()
:
    name("Default"),
    isSigned(false),
    gradeToSign(50),
    gradeToExecute(100)
{}

AForm::AForm(
    std::string name,
    bool isSigned,
    int gradeToSign,
    int gradeToExecute)
:
    name(name),
    isSigned(isSigned),
    gradeToSign(gradeToSign),
    gradeToExecute(gradeToExecute)
{

    //std::cout << "Constructor" << std::endl;

	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
	else if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}

}

AForm::AForm(const AForm &other)
:
    name(other.name),
    isSigned(other.isSigned),
    gradeToSign(other.gradeToSign),
    gradeToExecute(other.gradeToExecute)
{

}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
	return (*this);
}

AForm::~AForm()
{

}

const std::string &AForm::getName() const
{
	return (name);
}

int AForm::getGradeToSign() const
{
	return (gradeToSign);
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}

void AForm::beSigned(Bureaucrat &b)
{
	if (gradeToSign >= b.getGrade())
	{
		isSigned = true;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form: grade too low";
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form: grade too high";
}

const char *AForm::FormNotSigned::what() const throw()
{
    return "Form: not signed.";
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned)
        throw AForm::FormNotSigned();

    if (executor.getGrade() > gradeToExecute)
        throw AForm::GradeTooLowException();

    executeFinal();
}


std::ostream &operator<<(std::ostream &os, const AForm &f)
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
