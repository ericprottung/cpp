#include <exception>
#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Form& form) {
   os << "Name: " << form.getName() << "\n";
   os << "Sign state: " << form.getSignState() << "\n";
   os << "Lowest grade to execute: " << form.getExecPermission() << "\n";
   os << "Lowest grade to sign: " << form.getSignPermission() << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return os;
}

int main() {
    try {
        Bureaucrat Frank("Frank", 1);
        Form fireEmployees("fireEmployees", 10, 100);
        Frank.signForm(fireEmployees);
        for (int i = 0; i < 50; ++i) {
           Frank.decrementGrade(); 
        }
        std::cout << fireEmployees;
        std::cout << Frank;
        Frank.signForm(fireEmployees);
        for (int i = 0; i < 50; i++) {
           Frank.incrementGrade(); 
        }
        Frank.signForm(fireEmployees);
        Form wrongConstruction("im wrong", 0, 151);
    }
    catch (std::exception &e) {
        std::cout << "Construction error: " <<e.what();
    } 
}