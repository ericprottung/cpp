/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:43:50 by eprottun          #+#    #+#             */
/*   Updated: 2026/03/01 19:09:12 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	for (int i = 0; i < 100; ++i) {
		if (i % 2)
			ideas[i] = "I wanna playy";
		else
			ideas[i] = "I wanna eaaat";
	}
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor" << std::endl;
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = other.ideas[i];
	}
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator" << std::endl;
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor" << std::endl;
}

void    Brain::printIdeas() const{
    for (unsigned int i = 0; i < 100; ++i)
        std::cout << ideas[i] << "\n";
}

void    Brain::setIdea(unsigned int pos, const std::string &idea) {
    ideas[pos] = idea;
}
