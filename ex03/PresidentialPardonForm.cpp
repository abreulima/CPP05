#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm()
:
AForm("PresidentialPardonForm", false, 25, 5), target("PresidentialPardonTarget")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
:
AForm(target, false, 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
:
AForm(other), target(other.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
	return *this;
}

void PresidentialPardonForm::executeFinal() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblerox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}