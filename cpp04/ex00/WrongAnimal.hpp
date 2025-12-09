/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:56:51 by eprottun          #+#    #+#             */
/*   Updated: 2025/12/09 12:22:16 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

using std::string;
using std::endl;
using std::cout;

class WrongAnimal {
	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator+(const WrongAnimal& other);
		~WrongAnimal();

		virtual void	makeSound() const;
		string	getType() const;
	protected :
		string type;
}	;

#endif