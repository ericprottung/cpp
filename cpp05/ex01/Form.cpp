#include "Form.hpp"
#include <iostream>

Form::Form() : name("deleteHumanity") , isSigned(false), execPermission(1), signPermission(10) {}

Form::Form(Form &other) : name(other.name),
                        isSigned(other.isSigned),
                        execPermission(other.execPermission),
                        signPermission(other.signPermission) {}

Form::Form(const std::string& newName, const int execPerm, const int signPerm) : name(newName) , isSigned(0), execPermission(execPerm), signPermission(signPerm) {}

Form& Form::operator=(const Form &other) {
    return *this;
}

Form::~Form(){}

const std::string& Form::getName() const{
    return name;
} 

const int Form::getSignPermission() const{
    return signPermission;
} 

const int Form::getExecPermission() const {
    return execPermission;
} 

const bool Form::getSignState() const{
    return isSigned;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
   os << "Name: " << form.getName() << "\n";
   os << "Sign state: " << form.getSignState() << "\n";
   os << "Lowest grade to execute: " << form.getExecPermission() << "\n";
   os << "Lowest grade to sign: " << form.getSignPermission() << "\n";
    return os;
}