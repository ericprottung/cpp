/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:49:50 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/28 16:51:11 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	cout << "FragTrap default constructor has been called" << endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

FragTrap::FragTrap(string name) : ClapTrap(name) {
	cout << "FragTrap param constructor has been called" << endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
	cout << "FragTrap copy constructor has been called" << endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	cout << "FragTrap copy assignment constructor has been called" << endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap() {
	cout << "FragTrap destructor has been called" << endl;
}

void FragTrap::highFivesGuys() {
	cout << "ScavTrap " << name << " is requesting a high five!" << endl;
}

