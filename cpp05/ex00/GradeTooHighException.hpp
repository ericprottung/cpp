#include <exception>

class GradeTooHighException : public std::exception {
    const char * what() {
        return "GradeTooHighException";
    }
}   ;
