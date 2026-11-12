#include "Bureaucrat.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    
    // canonical stuff
    Bureaucrat c0 = Bureaucrat();               // OK
    Bureaucrat c1 = Bureaucrat(c0);             // OK
    Bureaucrat c2 = Bureaucrat("Zuko", 100);    // OK

    std::cout << c2 << std::endl;
    c2 = c1;
    
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;

    // return 0;

    Bureaucrat b1 = Bureaucrat("Xaolin", 1);    // OK

    try
    {
        Bureaucrat b2 = Bureaucrat("Lime", 0);      // NOK
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat b3 = Bureaucrat("Lemon", 151);   // NOK
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    Bureaucrat b4("John", 2);
    b4.incrementGrade(); // grade 1
    
    try
    {
        b4.incrementGrade(); // tenta passar da grade 1; lança exceção
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    Bureaucrat b5 = Bureaucrat("Ringo", 150);   // OK

    try 
    {
        b5.decrementGrade();                        // NOK
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Print b (this is cool)
    std::cout << b1 << std::endl;

    // Use try, catch syntax to control the excepts, instead of automatically exiting
    try 
    {
        b1.incrementGrade();
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    
    return 0;
}