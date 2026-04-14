/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:26:38 by eprottun          #+#    #+#             */
/*   Updated: 2026/03/01 16:54:52 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal& other) {
	type = other.type;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	type = other.type;
	std::cout << "Animal assignment operator" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor" << std::endl;
}

std::string	Animal::getType() const {
	return type;
}
