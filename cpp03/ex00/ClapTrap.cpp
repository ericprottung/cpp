/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:49:50 by eprottun          #+#    #+#             */
/*   Updated: 2026/02/26 22:11:46 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Param constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage){
	std::cout << "Copy constructor has been called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment constructor has been called" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor has been called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		--energyPoints;
	}
	else if (hitPoints > 0)
		std::cout << "ClapTrap " << name << " doesn't have enough energy points to attack!" << std::endl;
	else
		std::cout << "ClapTrap " << name << " can't rise up from the dead to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
	else if (hitPoints > amount)
	{
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
		hitPoints -= amount;
	}
	else
	{
		std::cout << "ClapTrap " << name << " has been killed by " << amount << " points of damage!" << std::endl;
		hitPoints = 0;
	}
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " recovers " << amount << " hitpoints!" << std::endl;
		--energyPoints;
		hitPoints += amount;
	}
	else if (hitPoints > 0)
		std::cout << "ClapTrap " << name << " doesn't have enough energy points to recover hitpoints!" << std::endl;
	else
		std::cout << "ClapTrap " << name << " can't revive itself!" << std::endl;
}

void ClapTrap::setAttackDamage(unsigned int amount) {
	std::cout << "ClapTrap " << name << " can now attack with " << amount << " of attack damage!" << std::endl;
	attackDamage = amount;
}

std::string ClapTrap::getName() {
	return name;
}

