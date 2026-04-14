/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:44:49 by eprottun          #+#    #+#             */
/*   Updated: 2026/03/01 19:10:53 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	if (this != &other) {
		brain = new Brain();
		*brain = *other.brain;
	}
	type = other.type;
	std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		*brain = *other.brain;
	}
	type = other.type;
	std::cout << "Dog assignment operator" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Yo I bark!" << std::endl;
}

void	Dog::setIdea(const std::string& idea, int pos) {
	if (pos >= 0 && pos < 100)
	    brain->setIdea(pos, idea);
}
		
void	Dog::printIdeas() const {
    brain->printIdeas();
}
