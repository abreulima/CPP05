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
    Bureaucrat b2 = Bureaucrat("Lime", 0);      // NOK
    Bureaucrat b3 = Bureaucrat("Lemon", 151);   // NOK

    Bureaucrat b4 = Bureaucrat("John", 2);      // OK
    b4.incrementGrade();                        // OK
    b4.incrementGrade();                        // NOK

    Bureaucrat b5 = Bureaucrat("Ringo", 150);   // OK
    b5.decrementGrade();                        // NOK

    // Print b (this is cool)
    std::cout << b1 << std::endl;

    // Use try, catch syntax to control the excepts, instead of automatically exiting
    try {
        b1.incrementGrade();
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    
    return 0;
}