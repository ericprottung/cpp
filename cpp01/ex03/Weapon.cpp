/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:10:40 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/08 13:02:36 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::get_type() {
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}

Weapon::Weapon(std::string type) {
	this->type = type;
}