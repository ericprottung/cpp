#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Form {
    public :
        Form();
        Form(Form &other);
        Form(const std::string& newName, const int signPerm, const int execPerm);
        Form& operator=(const Form &other);
        ~Form();
        const std::string& getName() const; 
        const int getSignPermission() const; 
        const int getExecPermission() const; 
        const bool getSignState() const;
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
        const int signPermission;
        const int execPermission;
}   ;

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif