/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:12:12 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/26 11:55:50 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
	public	:
		void attack();
		
		HumanA(std::string name, Weapon& weapon) {
			this->name = name;
			this->weapon = &weapon;
		}
	private	:
		std::string name;
		Weapon* weapon;
} ;
#endif