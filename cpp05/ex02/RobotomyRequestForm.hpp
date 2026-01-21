#ifndef ROBOTOMYREQUESTFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        virtual void    execute(Bureaucrat const & executor) const;
        const std::string& getTarget() const;
    private :
        const std::string target;
}   ;

#endif