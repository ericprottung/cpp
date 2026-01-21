#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137) , target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other) : AForm(other.getName(), other.getSignPermission(), other.getSignPermission()), target(other.target) {
    
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    (void)other;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getSignState())
        throw std::runtime_error("Form is not signed!");
    if (getExecPermission() < executor.getGrade())
        throw GradeTooLowException();
    
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open())
        throw std::runtime_error("File couldn't be opened!");
    
    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";
}

const std::string& ShrubberyCreationForm::getTarget() const {
   return target;
}