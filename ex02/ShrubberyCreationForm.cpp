#include <fstream>
#include <stdexcept>

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
:
AForm("ShrubberyCreationForm", false, 145, 137), target("DefaultTarget")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
:
AForm("ShrubberyCreationForm", false, 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
:
AForm(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
	return *this;
}

void ShrubberyCreationForm::executeFinal() const
{
    std::ofstream file((target + "_shrubbery").c_str());

    if (!file.is_open())
        throw std::runtime_error("Unable to create file");

    file << "               ,@@@@@@@,\n";
    file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
    file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
    file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
    file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
    file << "       |o|        | |         | |\n";
    file << "       |.|        | |         | |\n";
    file << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";

    file.close();
    
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}