/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:59:30 by eprottun          #+#    #+#             */
/*   Updated: 2025/12/09 12:22:21 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	type = other.type;
}

WrongAnimal& WrongAnimal::operator+(const WrongAnimal& other) {
	type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {}

string	WrongAnimal::getType() const {
	return type;
}

void	WrongAnimal::makeSound() const {
	cout << "I shouldn't make a sound" << endl;
}