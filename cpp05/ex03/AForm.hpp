#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Bureaucrat;

class AForm {
    public :
        AForm();
        AForm(AForm &other);
        AForm(const std::string& newName, const int signPerm, const int execPerm);
        AForm& operator=(const AForm &other);
        virtual ~AForm();
        
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
		virtual void execute(Bureaucrat const & executor) const = 0;
    private:
        const std::string name;
        bool  isSigned;
        const int execPermission;
        const int signPermission;
}   ;

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif