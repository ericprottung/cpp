/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:45:18 by eprottun          #+#    #+#             */
/*   Updated: 2025/12/09 14:02:52 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(){
	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
	type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
	type = other.type;
	return *this;
}

Cat::~Cat() {}

void Cat::makeSound() const {
	std::cout << "I can only meow!" << std::endl;
}
