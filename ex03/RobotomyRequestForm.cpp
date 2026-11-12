#include "RobotomyRequestForm.hpp"

#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
:
AForm("RobotomyRequestForm", false, 72, 45), target("RobotomyRequestFormTarget")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:
AForm("RobotomyRequestForm", false, 72, 45), target(target)
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
    std::cout << "* drilling noises *" << std::endl;

    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed for " << target << "." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}
