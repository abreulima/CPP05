#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class AForm 
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
        
    public:
        AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
        AForm(); // Default Constructor
        AForm(const AForm& other); // Copy constructor
        AForm& operator=(const AForm& other); // = overload
        virtual ~AForm(); // desctructor

        void execute(Bureaucrat const & executor) const;
        virtual void executeFinal() const = 0; // virtual (can override) = 0 (must be implemented)

        // Getters
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat &b);

        // Exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class FormNotSigned : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif