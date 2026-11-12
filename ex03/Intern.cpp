#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstddef>

Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
	(void) other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void) other;
	return (*this);
}

Intern::~Intern()
{

}

AForm* Intern::makeForm(const std::string form, std::string target)
{
    std::string forms[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int i;
    for (i = 0; i < 3 && form != forms[i]; i++);

    switch (i) {
        case 0:
            std::cout << "Intern creates " << form << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates "  << form << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " << form << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cerr << "Failed to create a form" << std::endl;
            return NULL;
    }
}
