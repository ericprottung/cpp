/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:45:18 by eprottun          #+#    #+#             */
/*   Updated: 2026/03/01 19:10:37 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	if (this != &other){
		brain = new Brain();
		*brain = *other.brain;
	}
	type = other.type;
	std::cout << "Cat copy constructor" << std::endl;

}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		*brain = *other.brain;
	type = other.type;
	std::cout << "Cat assignment operator" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "I can only meow!" << std::endl;
}

void	Cat::setIdea(const std::string& idea, int pos) {
	if (pos >= 0 && pos < 100)
		brain->ideas[pos] = idea;
}
		
void	Cat::printIdeas() const {
	for (int i = 0; i < 100; ++i) {
		std::cout << brain->ideas[i] << "\n";
	}
}
