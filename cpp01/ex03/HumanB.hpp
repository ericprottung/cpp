/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:33:12 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/08 10:36:48 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
	public	:
		HumanB(std::string name);
		
		void attack();
		void setWeapon(Weapon& weapon);	
	private	:
		std::string name;
		Weapon* weapon;
} ;
#endif