#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	int grade = 150;
	std::string name = NULL;
}

Bureaucrat::Bureaucrat(int newGrade) {
	try {
		if (newGrade > 150)
			throw GradeTooHighException;
		if (newGrade < 1)
			throw GradeTooLowException;
	}
	catch (GradeTooHighException) {

	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {

}

Bureaucrat::~Bureaucrat() {

}

std::exception Bureaucrat::GradeTooHighException() {

}

const std::string& Bureaucrat::getName() const {

}

const int Bureaucrat::getGrade() const {

}

void Bureaucrat::incrementGrade(int amount) {
	try {
		if (this->grade == 150)
			throw GradeTooHighException;
	} catch (GradeTooHighException) {
	
	}
}

void Bureaucrat::decrementGrade(int amount) {

}
