#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    Intern someRandomIntern;
    AForm* rrf;
    AForm* rrf2;
    
    
    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    rrf2 = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    
    // Can someone sign/execute this?
    Bureaucrat king("TheKing", 1);

    king.signForm(*rrf);
    king.executeForm(*rrf);

    king.signForm(*rrf2);
    king.executeForm(*rrf2);
    
    delete rrf;
    delete rrf2;
    return 0;
}