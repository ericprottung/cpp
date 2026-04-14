/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:45:18 by eprottun          #+#    #+#             */
/*   Updated: 2026/03/01 19:11:38 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	brain = new Brain();
	type = "WrongCat";
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	type = other.type;
	if (this != &other) {
		brain = new Brain();
		*brain = *other.brain;
	}
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	type = other.type;
	if (this != &other) {
		*brain = *other.brain;
	}
	std::cout << "WrongCat assignment operator" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	delete brain;
	std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "I meow loudly!" << std::endl;
}

void	WrongCat::setIdea(const std::string& idea, int pos) {
	if (pos >= 0 && pos < 100)
		brain->ideas[pos] = idea;
}
		
void	WrongCat::printIdeas() const {
	for (int i = 0; i < 100; ++i) {
		std::cout << brain->ideas[i] << "\n";
	}
}
