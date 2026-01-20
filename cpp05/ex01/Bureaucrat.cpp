#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "GradeTooHighException\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "GradeTooLowException\n";
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
