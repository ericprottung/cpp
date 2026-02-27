/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:56:51 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/06 17:49:23 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal {
	public :
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		~Animal();

		virtual void	makeSound() const;
		std::string	getType() const;
	protected :
		std::string type;
}	;

#endif