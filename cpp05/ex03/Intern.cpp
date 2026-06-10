#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

Intern::Intern() {
    
}

Intern::Intern(const Intern &other){
}

Intern& Intern::operator=(const Intern &other){
    (void)other;
    return *this;
}

Intern::~Intern(){}

AForm *Intern::makeForm(std::string nameOfForm, std::string target){
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3; ++i) {
        if (nameOfForm == names[i]) {
            if (i == 0) {
                std::cout << "Intern creates: " << names[i] << "\n";
                return new ShrubberyCreationForm(target);
            }
            if (i == 1) {
                std::cout << "Intern creates: " << names[i] << "\n";
                return new RobotomyRequestForm(target);
            }
            if (i == 2) {
                std::cout << "Intern creates: " << names[i] << "\n";
                return new PresidentialPardonForm(target);
            }
        }
    }
    throw std::runtime_error("Wrong name provided!");
}