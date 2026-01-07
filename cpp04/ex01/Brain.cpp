/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:43:50 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/06 17:49:26 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	
}

Brain::Brain(const Brain& other) {
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	type = other.type;
	return *this;
}

Brain::~Brain() {}

string	Brain::getType() const {
	return type;
}

void	Brain::makeSound() const {
	cout << "I shouldn't make a sound" << endl;
}