#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat() : name("Agent Smith"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
};

// called by Bureacrat newb(old), creates a new one
Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.name), grade(b.grade) {};

// Change the grade of the object (left side) to the object of the right side
// b = b2, means that b will have the grade (only) of b2
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &b)
{
    if (this != &b)
        grade = b.grade;
    return *this;
}

int Bureaucrat::getGrade() const {
    return grade;
}

const std::string& Bureaucrat::getName() const {
    return name;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw  GradeTooLowException();
    grade++;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called." << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high. Grades can't be higher than 1";
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low. Grades can't be lower than 150";
};

void Bureaucrat::signForm(Form &form)
{
    try 
    {
        form.beSigned(*this);
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't sign " << form.getName() << " because " 
        << e.what() << std::endl; 
        return ;
    }
    std::cout << name << " signed " << form.getName(); 
}

// overload <<  when used with class Bureaucrat
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
  os << b.getName() <<", bureaucrat grade " << b.getGrade() << ".";
  return os;
};