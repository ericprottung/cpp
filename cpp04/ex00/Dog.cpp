/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:44:49 by eprottun          #+#    #+#             */
/*   Updated: 2025/12/01 11:58:32 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
}

Dog::Dog(const Dog& other) {
	type = other.type;
}

Dog& Dog::operator+(const Dog& other) {
	type = other.type;
	return *this;
}

Dog::~Dog() {}

void Dog::makeSound() const {
	cout << "Yo I bark!" << endl;
}
