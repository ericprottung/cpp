#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Bureaucrat;

class Form {
    public :
        Form();
        Form(const Form &other);
        Form(const std::string& newName, const int signPerm, const int execPerm);
        Form& operator=(const Form &other);
        ~Form();
        const std::string& getName() const; 
        int getSignPermission() const; 
        int getExecPermission() const; 
        bool getSignState() const;
        void beSigned(Bureaucrat &bureaucrat);
        class GradeTooHighException : public std::exception {
		    public:
				virtual const char *what() const throw();
		};		
		class GradeTooLowException : public std::exception {
                  public:
		        virtual const char *what() const throw();
		};
    private:
        const std::string name;
        bool  isSigned;
        const int execPermission;
        const int signPermission;
}   ;

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif