#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    Bureaucrat king("King", 1);
    Bureaucrat peasant("Peasant", 100);

    Form allow("Allowed", 50, 25);
    Form deny("Denied", 50, 25);

    king.signForm(allow);
    peasant.signForm(deny);

    std::cout << allow << std::endl;
    std::cout << deny << std::endl;

    try 
    {
        Form invalid("InvalidForm", 0, 50);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        Form invalid1("Invalid1", 151, 50);
        
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    // Invalid Forms

    try 
    {
        Form invalid3("Invalid3", 50, 0);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    
    try 
    {
        Form invalid4("Invalid4", 50, 151);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
