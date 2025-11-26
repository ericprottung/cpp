/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:33:12 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/26 11:59:47 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	public	:
		void attack();
		void setWeapon(Weapon& weapon);
		
		HumanB(std::string name) : name(name), weapon(NULL) {}
	private	:
		std::string name;
		Weapon* weapon;
} ;
#endif