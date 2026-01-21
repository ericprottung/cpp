#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Shrubbery", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Shrubbery", 72, 45) , target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other) : AForm(other.getName(), other.getSignPermission(), other.getSignPermission()), target(other.target) {
    
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    (void)other;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
   if (!getSignState())
       throw std::runtime_error("Form is not signed!");
   if (getExecPermission() < executor.getGrade())
       throw GradeTooLowException();
   std::cout << "*DRILLING NOISES*\n";
   bool success = rand() % 2;
   if (success)
       std::cout << getTarget() << " has been robotomized successfully!\n";
   else
       std::cout << "Robotomy failed!\n";
}

const std::string& RobotomyRequestForm::getTarget() const {
   return target;
}