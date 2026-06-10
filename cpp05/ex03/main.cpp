#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));

    try {
        Bureaucrat bob("Bob", 130);
        ShrubberyCreationForm shrub("home");
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat intern("Intern", 145);
        ShrubberyCreationForm shrub("office");
        intern.signForm(shrub);
        intern.executeForm(shrub);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("Bender");
        boss.signForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("Marvin");
        boss.executeForm(robot);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat lowGrade("LowGrade", 50);
        PresidentialPardonForm pardon("Ford Prefect");
        lowGrade.signForm(pardon);
        lowGrade.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat god("God", 1);
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("R2D2");
        PresidentialPardonForm pardon("Zaphod");
        god.signForm(shrub);
        god.signForm(robot);
        god.signForm(pardon);
        god.executeForm(shrub);
        god.executeForm(robot);
        god.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat boss("Boss", 1);
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Intern someRandomIntern;
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
        Bureaucrat bob("Bob", 130);
        bob.signForm(*scf);
        bob.executeForm(*scf);
        delete scf;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Intern someRandomIntern;
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Zaphod");
        Bureaucrat president("President", 1);
        president.signForm(*ppf);
        president.executeForm(*ppf);
        delete ppf;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Intern someRandomIntern;
        AForm* unknown = someRandomIntern.makeForm("doing the dishes", "Bob");
        delete unknown;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}