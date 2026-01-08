/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:41:27 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/08 11:46:20 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

void HumanB::attack() {
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->get_type() << std::endl;
	else
		std::cout << this->name << " has no weapon" << std::endl;		
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
}