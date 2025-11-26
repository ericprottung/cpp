/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:57:06 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/25 18:11:32 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	public :
		Zombie(std::string name) {
			this->name = name;
		}
		~Zombie() {
			std::cout << this->name << " died!" << std::endl;
		}
		void	announce();
	private :
		std::string name;
} ;

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif