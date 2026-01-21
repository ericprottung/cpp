#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdexcept>
#include <string>

Intern::Intern() {
    
}

Intern::Intern(Intern &other){
}

Intern& Intern::operator=(const Intern &other){
    (void)other;
    return *this;
}

Intern::~Intern(){}

AForm *Intern::makeForm(std::string nameOfForm, std::string target){
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    ShrubberyCreationForm *scform = new ShrubberyCreationForm(target);
    RobotomyRequestForm *rrform = new RobotomyRequestForm(target);
    PresidentialPardonForm *ppform = new PresidentialPardonForm(target);
    AForm *forms[3] = {scform, rrform, ppform};
    for (int i = 0; i < 3; i++) {
        if (!nameOfForm.compare(names[i]))
            return forms[i];
        delete forms[i];
    }
    throw std::runtime_error("Wrong name provided!");
}