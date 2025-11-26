/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:05:20 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/25 18:31:05 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie* zombie = new Zombie[N];
	for (size_t i = 0; i < (size_t)N; i++)
	{
		zombie[i].set_name(name);
	}
	return zombie;
}