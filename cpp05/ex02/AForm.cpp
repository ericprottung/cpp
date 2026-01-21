#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

AForm::AForm() : name("deleteHumanity") , isSigned(false), execPermission(1), signPermission(10) {}

AForm::AForm(AForm &other) : name(other.name),
                        isSigned(other.isSigned),
                        execPermission(other.execPermission),
                        signPermission(other.signPermission) {}

AForm::AForm(const std::string& newName, int signPerm, const int execPerm) : name(newName) , isSigned(0), execPermission(execPerm), signPermission(signPerm){
    if (execPerm > 150 || signPerm > 150)
        throw GradeTooLowException();    
    if (execPerm < 1 || signPerm < 1)
        throw GradeTooHighException();
}

AForm& AForm::operator=(const AForm &other) {
    (void)other;
    return *this;
}

AForm::~AForm(){}

const char* AForm::GradeTooHighException::what() const throw() {
    return "GradeTooHighException";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "GradeTooLowException";
}
const std::string& AForm::getName() const{
    return name;
} 

int AForm::getSignPermission() const{
    return signPermission;
} 

int AForm::getExecPermission() const {
    return execPermission;
} 

bool AForm::getSignState() const{
    return isSigned;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
   os << "Name: " << form.getName() << "\n";
   os << "Sign state: " << form.getSignState() << "\n";
   os << "Lowest grade to execute: " << form.getExecPermission() << "\n";
   os << "Lowest grade to sign: " << form.getSignPermission() << "\n";
    return os;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (signPermission < bureaucrat.getGrade())
        throw GradeTooLowException();
    if (isSigned)
        throw std::runtime_error("Form is already signed!\n");
    isSigned = true;
}