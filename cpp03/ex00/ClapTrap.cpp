/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:49:50 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/28 15:29:44 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0) {
	cout << "Default constructor has been called" << endl;
}

ClapTrap::ClapTrap(string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	cout << "Param constructor has been called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage){
	cout << "Copy constructor has been called" << endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	cout << "Copy assignment constructor has been called" << endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap() {
	cout << "Destructor has been called" << endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0)
	{
		cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << endl;
		energyPoints--;
	}
	else if (hitPoints > 0)
		cout << "ClapTrap " << name << " doesn't have enough energy points to attack!" << endl;
	else
		cout << "ClapTrap " << name << " can't rise up from the dead to attack!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0)
		cout << "ClapTrap " << name << " is already dead!" << endl;
	else if (hitPoints > amount)
	{
		cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << endl;
		hitPoints -= amount;
	}
	else
	{
		cout << "ClapTrap " << name << " has been killed by " << amount << " points of damage!" << endl;
		hitPoints = 0;
	}
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0)
	{
		cout << "ClapTrap " << name << " recovers " << amount << " hitpoints!" << endl;
		energyPoints--;
		hitPoints += amount;
	}
	else if (hitPoints > 0)
		cout << "ClapTrap " << name << " doesn't have enough energy points to recover hitpoints!" << endl;
	else
		cout << "ClapTrap " << name << " can't revive itself!" << endl;
}

void ClapTrap::setAttackDamage(unsigned int amount) {
	cout << "ClapTrap " << name << " can now attack with " << amount << " of attack damage!" << endl;
	attackDamage = amount;
}

string ClapTrap::getName() {
	return name;
}

