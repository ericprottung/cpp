#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

class AForm;

class  Intern   {
    Intern();
    Intern(Intern &other);
    Intern& operator=(const Intern &other);
    ~Intern();
    AForm *makeForm(std::string nameOfForm, std::string target);
}   ;

#endif