/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:44:49 by eprottun          #+#    #+#             */
/*   Updated: 2026/03/01 16:59:58 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	type = "Dog";
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	type = other.type;
	std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	type = other.type;
	std::cout << "Dog assignment operator" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Yo I bark!" << std::endl;
}
