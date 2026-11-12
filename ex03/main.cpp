#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstddef>
#include <ctime>
#include <cstdlib>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    std::srand(static_cast<unsigned int>(std::time(NULL)));
     
    Intern someRandomIntern;
    AForm* shrubbery;
    AForm* robotomy;
    AForm* pardon;

    shrubbery = someRandomIntern.makeForm("shrubbery creation", "Bender");
    robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
    pardon = someRandomIntern.makeForm("presidential pardon", "Bender");

    if (shrubbery == NULL || robotomy == NULL || pardon == NULL)
    {
        delete shrubbery;
        delete robotomy;
        delete pardon;
        return 1;
    }
    
    // Can someone sign/execute this?
    Bureaucrat king("TheKing", 1);

    king.signForm(*shrubbery);
    king.executeForm(*shrubbery);

    king.signForm(*robotomy);
    king.executeForm(*robotomy);

    king.signForm(*pardon);
    king.executeForm(*pardon);

    AForm* errorForm = someRandomIntern.makeForm("Error", "Bender"); // it will return null

    delete errorForm; // It is okay to delete a NULL!
    delete shrubbery;
    delete robotomy;
    delete pardon;
    return 0;
}
