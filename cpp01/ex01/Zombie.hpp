/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:57:06 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/25 18:21:49 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	public :
		Zombie() {
		}
		Zombie(std::string name) {
			this->name = name;
		}
		~Zombie() {
			std::cout << this->name << " died!" << std::endl;
		}
		void	set_name(std::string input);
		void	announce();
	private :
		std::string name;
} ;

Zombie* zombieHorde( int N, std::string name );

#endif