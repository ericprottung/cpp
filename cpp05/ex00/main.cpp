#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "\n";
	return os;
}

int main() {
    try {
        Bureaucrat Bob(151);
        Bureaucrat Jonny("Jonny", 0);
        Bureaucrat Frank("Frank", 1);
        std::cout << Frank;
        Frank.incrementGrade();
        Frank.decrementGrade();
        std::cout << Frank;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }    
    try {
        Bureaucrat Jonny("Jonny", 0);
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }    
    try {
        Bureaucrat Frank("Frank", 1);
        std::cout << Frank;
        Frank.decrementGrade();
        std::cout << Frank;
        Frank.incrementGrade();
        std::cout << Frank;
        Frank.incrementGrade();
        std::cout << Frank;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    return 0;
}