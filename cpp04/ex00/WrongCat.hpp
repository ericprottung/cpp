/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:31:14 by eprottun          #+#    #+#             */
/*   Updated: 2025/12/09 12:20:28 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public Animal{
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator+(const WrongCat& other);
		~WrongCat();
}	;

#endif