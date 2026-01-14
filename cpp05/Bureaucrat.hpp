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

# include <exception>
# include <string>

class GradeTooHighException : std::exception {
		
}	;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(int newGrade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		std::exception GradeTooHighException();
		const std::string& getName() const;
		const int getGrade() const;
		void incrementGrade(int amount);
		void decrementGrade(int amount);
	private:
		const std::string name;
		int grade;
}	;

#endif