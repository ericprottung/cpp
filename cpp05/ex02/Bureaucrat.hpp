/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:55:45 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/11 12:31:06 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class AForm;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(int newGrade);
		Bureaucrat(const std::string &name, int newGrade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		const std::string& getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &toSign);
		void executeForm(AForm const & form) const;
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
		int grade;
}	;

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif