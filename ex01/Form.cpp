#include "Form.hpp"

Form::Form(
    std::string name, 
    bool isSigned, 
    int gradeToSign, 
    int gradeToExecute) 
:
    name(name),
    isSigned(isSigned), 
    gradeToSign(gradeToSign), 
    gradeToExecute(gradeToExecute) 
{}