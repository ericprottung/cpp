/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:12:12 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/08 11:44:05 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
	public	:
		HumanA(std::string name, Weapon& w);
	
		void attack();
	private	:
		std::string name;
		Weapon& weapon;
} ;
#endif