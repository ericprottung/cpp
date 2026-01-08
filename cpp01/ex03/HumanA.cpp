/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:17:07 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/08 11:43:56 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

void HumanA::attack() {
	std::cout << this->name << " atacks with their " << this->weapon.get_type() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& w) : weapon(w) {
		this->name = name;
}