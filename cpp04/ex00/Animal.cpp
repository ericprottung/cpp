/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:26:38 by eprottun          #+#    #+#             */
/*   Updated: 2025/12/09 14:02:29 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	
}

Animal::Animal(const Animal& other) {
	type = other.type;
}

Animal& Animal::operator=(const Animal& other) {
	type = other.type;
	return *this;
}

Animal::~Animal() {}

string	Animal::getType() const {
	return type;
}

void	Animal::makeSound() const {
	cout << "I shouldn't make a sound" << endl;
}