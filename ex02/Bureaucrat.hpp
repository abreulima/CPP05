#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>
#include <ostream>

class AForm;

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:

        // Start of Orthodox Canonical Form
        Bureaucrat();                                   // default constuctor
        Bureaucrat(std::string, int grade);             // constructor w/ args
        Bureaucrat(const Bureaucrat& b);                // cpy constructor
        Bureaucrat& operator=(const Bureaucrat& b);     // copy overloard=
        ~Bureaucrat();                                  // destructor
        // End

        int getGrade() const;
        const std::string& getName() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &aform);
        void executeForm(AForm &aform);
        
        class GradeTooHighException : public std::exception 
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif