#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));
    std::cout << "=== TEST 1: ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 130);
        ShrubberyCreationForm shrub("home");
        
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        
        bob.signForm(shrub);
        bob.executeForm(shrub);
        std::cout << "✓ File home_shrubbery should be created!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 2: ShrubberyCreationForm - Grade too low to execute ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 145);
        ShrubberyCreationForm shrub("office");
        
        intern.signForm(shrub);
        intern.executeForm(shrub);  // Should fail - grade 145, needs 137
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 3: RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("Bender");
        
        boss.signForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);  // Try multiple times to see 50% success rate
        boss.executeForm(robot);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 4: RobotomyRequestForm - Not signed ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("Marvin");
        
        boss.executeForm(robot);  // Should fail - not signed
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 5: PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 6: PresidentialPardonForm - Grade too low ===" << std::endl;
    try {
        Bureaucrat lowGrade("LowGrade", 50);
        PresidentialPardonForm pardon("Ford Prefect");
        
        lowGrade.signForm(pardon);  // Should fail - needs grade 25
        lowGrade.executeForm(pardon);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 7: All forms with perfect bureaucrat ===" << std::endl;
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
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 8: Form construction exceptions ===" << std::endl;
    try {
        ShrubberyCreationForm invalid("test");  // Should work
        std::cout << "✓ ShrubberyCreationForm created successfully" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}