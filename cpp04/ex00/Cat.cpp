/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:45:18 by eprottun          #+#    #+#             */
/*   Updated: 2025/12/01 11:54:49 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
}

Cat::Cat(const Cat& other) {
	type = other.type;
}

Cat& Cat::operator+(const Cat& other) {
	type = other.type;
	return *this;
}

Cat::~Cat() {}

void Cat::makeSound() const {
	cout << "I can only meow!" << endl;
}
