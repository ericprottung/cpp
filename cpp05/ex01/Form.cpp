#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>

Form::Form() : name("deleteHumanity") , isSigned(false), execPermission(1), signPermission(10) {}

Form::Form(const Form &other) : name(other.name),
                        isSigned(other.isSigned),
                        execPermission(other.execPermission),
                        signPermission(other.signPermission) {}

Form::Form(const std::string& newName, int signPerm, const int execPerm) : name(newName) , isSigned(0), execPermission(execPerm), signPermission(signPerm){
    if (execPerm > 150 || signPerm > 150)
        throw GradeTooLowException();    
    if (execPerm < 1 || signPerm < 1)
        throw GradeTooHighException();
}

Form& Form::operator=(const Form &other) {
    isSigned = other.isSigned;
    return *this;
}

Form::~Form(){}

const char* Form::GradeTooHighException::what() const throw() {
    return "GradeTooHighException\n";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "GradeTooLowException\n";
}
const std::string& Form::getName() const{
    return name;
} 

int Form::getSignPermission() const{
    return signPermission;
} 

int Form::getExecPermission() const {
    return execPermission;
} 

bool Form::getSignState() const{
    return isSigned;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (signPermission < bureaucrat.getGrade())
        throw GradeTooLowException();
    if (isSigned)
        throw std::runtime_error("Form is already signed!\n");
    isSigned = true;
}