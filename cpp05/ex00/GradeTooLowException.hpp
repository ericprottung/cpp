#include <exception>

class GradeTooLowException : public std::exception {
    const char * what() {
        return "GradeTooLowException";
    }
}   ;
