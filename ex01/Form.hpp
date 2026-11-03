#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form 
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
        
    public:
        Form(); // Default Constructor
        Form(std::string name, int gradeToSign, int gradeToExecute); // Constructor with Args.
        Form(const Form& other); // Copy constructor
        Form& operator=(const Form& other); // = overload
        ~Form(); // desctructor

        // Getters, Setters
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

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif