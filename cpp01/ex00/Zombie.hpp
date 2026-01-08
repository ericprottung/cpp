/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:57:06 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/07 18:15:24 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	public :
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce();
	private :
		std::string name;
} ;

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif