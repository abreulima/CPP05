#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::numOp = 0;

RobotomyRequestForm::RobotomyRequestForm()
:
AForm("RobotomyRequestForm", false, 72, 45), target("RobotomyRequestFormTarget")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:
AForm(target, false, 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
:
AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
	return *this;
}

void RobotomyRequestForm::executeFinal() const
{
    if (numOp % 2)
    {
        std::cout << "* drill noises * " << target << " has been robotomized" << std::endl;
    }
    else 
    {
        std::cout << target << " failed to have succefull robotomy operation." << std::endl;
    }
    numOp++;
    

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}