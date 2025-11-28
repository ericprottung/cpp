/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:49:50 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/28 16:39:41 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	cout << "ScavTrap default constructor has been called" << endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(string name) : ClapTrap(name) {
	cout << "ScavTrap param constructor has been called" << endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
	cout << "ScavTrap copy constructor has been called" << endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	cout << "ScavTrap copy assignment constructor has been called" << endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap() {
	cout << "ScavTrap destructor has been called" << endl;
}

void ScavTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0)
	{
		cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << endl;
		energyPoints--;
	}
	else if (hitPoints > 0)
		cout << "ScavTrap " << name << " doesn't have enough energy points to attack!" << endl;
	else
		cout << "ScavTrap " << name << " can't rise up from the dead to attack!" << endl;
}

void ScavTrap::guardGate() {
	cout << "ScavTrap " << name << " is now gatekeeping!" << endl;
}

