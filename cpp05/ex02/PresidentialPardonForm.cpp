#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
//#include <cstdlib>
//#include <stdexcept>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Shrubbery", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Shrubbery", 25, 5) , target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other) : AForm(other.getName(), other.getSignPermission(), other.getSignPermission()), target(other.target) {
    
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    (void)other;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
   if (!getSignState())
       throw std::runtime_error("Form is not signed!");
   if (getExecPermission() < executor.getGrade())
       throw GradeTooLowException();
   std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox!\n";
}

const std::string& PresidentialPardonForm::getTarget() const {
   return target;
}