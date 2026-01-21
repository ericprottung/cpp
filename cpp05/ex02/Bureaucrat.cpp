#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "GradeTooHighException";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "GradeTooLowException";
}

Bureaucrat::Bureaucrat() {
	grade = 150;
	std::string name = "BOB";
}

Bureaucrat::Bureaucrat(int newGrade) : name("BOB"){
    if (newGrade > 150)
			throw GradeTooLowException();
	if (newGrade < 1)
		throw GradeTooHighException();
	grade = newGrade;
}

Bureaucrat::Bureaucrat(const std::string& newName, const int newGrade) : name(newName) {
	if (newGrade > 150)
		throw GradeTooLowException();
	if (newGrade < 1)
		throw GradeTooHighException();
	grade = newGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) , grade(other.grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
   grade = other.grade;
   return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(AForm &toSign) {
    try {
        toSign.beSigned(*this);
        std::cout << name << " signed " << toSign.getName() << "\n";    
    } catch (std::exception &e) {
        std::cout << name << " couldn't sign " << toSign.getName() << " because " << e.what() << "\n";
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << "\n";
    }
    catch (std::exception &e) {
        std::cout << name << " couldn't execute " << form.getName() << " because of " << e.what() << "\n";
    }
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "\n";
	return os;
}