#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    // AForm forbidden;

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Bureaucrat theKing("The King", 1);
    Bureaucrat theSoldier("The Soldier", 75);
    Bureaucrat theFarmer("The Farmer", 150);

    PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm");
    RobotomyRequestForm robotomyRequestForm("RobotomyRequestForm");
    ShrubberyCreationForm shrubberyCreationForm("ShrubberyCreationForm");

    // Catch
    try 
    {
        theFarmer.signForm(presidentialPardonForm);
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cerr << "No able to sign the form due to low grade." << std::endl;
    }

    // Catch
    try 
    {
        //presidentialPardonForm.beSigned(theSoldier);
        theSoldier.signForm(presidentialPardonForm);
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cerr << "No able to sign the form due to low grade." << std::endl;
    }

    // Catch
    try 
    {
        presidentialPardonForm.execute(theFarmer);        
    }
    catch (AForm::FormNotSigned &e)
    {
        std::cerr << "Form not signed" << std::endl;
    }

    // No catch
    try 
    {
        theKing.signForm(presidentialPardonForm);
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cerr << "No able to sign the form due to low grade." << std::endl;
    }

    // No catch
    try 
    {
        presidentialPardonForm.execute(theKing);        
    }
    catch (AForm::FormNotSigned &e)
    {
        std::cerr << "Form not signed" << std::endl;
    }

    // No catch
    try 
    {
        theSoldier.signForm(robotomyRequestForm);
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cerr << "Failed to sign!" << std::endl;
    }

    // Catch - The Soldier can sign but not execute.
    try 
    {
        robotomyRequestForm.execute(theSoldier);
    }
    catch (AForm::FormNotSigned &e)
    {
        std::cerr << "Failed to sign!" << std::endl;
    }

    // No catch
    try 
    {
        robotomyRequestForm.execute(theKing);
    }
    catch (AForm::FormNotSigned &e)
    {
        std::cout << "Failed to sign!" << std::endl;
    }

    // Catch
    try 
    {
        //robotomyRequestForm.beSigned(theFarmer);
        theFarmer.signForm(robotomyRequestForm);
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cerr << "Grade too low to sign!" << std::endl;
    }

    // No Catch
    try 
    {
        //robotomyRequestForm.beSigned(theKing);
        theKing.signForm(robotomyRequestForm);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    // Catch
    try 
    {
        robotomyRequestForm.execute(theFarmer);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Nothing can throw
    {

        Bureaucrat k("The King", 1);

        PresidentialPardonForm p("Pikachu");
        RobotomyRequestForm r("Bender");
        ShrubberyCreationForm s("Sponge Bob");
        
        //p.beSigned(k);
        //r.beSigned(k);
        //s.beSigned(k);

        k.signForm(p);
        k.signForm(r);
        k.signForm(s);
        
        k.executeForm(p);
        k.executeForm(r);
        k.executeForm(s);
        
        std::cout << p << std::endl;
        std::cout << r << std::endl;
        std::cout << s << std::endl;
        
    }
    
    return 0;
}