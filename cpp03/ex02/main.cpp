/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:28:13 by eprottun          #+#    #+#             */
/*   Updated: 2026/02/26 20:58:57 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main () {
	ClapTrap one("John");
	ClapTrap two("Samuel");
	ScavTrap three("Lara");
	ScavTrap four("Amanda");
	one.attack(two.getName());
	two.takeDamage(0);
	one.attack(two.getName());
	two.takeDamage(0);
	one.attack(two.getName());
	two.takeDamage(0);
	one.attack(two.getName());
	two.takeDamage(0);
	std::cout << one.getName() << " forgot to pick up his axe and takes it!" << std::endl;
	one.setAttackDamage(2);
	one.attack(two.getName());
	two.takeDamage(2);
	one.attack(two.getName());
	two.takeDamage(2);
	one.attack(two.getName());
	two.takeDamage(2);
	one.attack(two.getName());
	two.takeDamage(2);
	std::cout << two.getName() << " finally responds!" << std::endl;
	two.beRepaired(1);
	two.beRepaired(1);
	two.beRepaired(1);
	two.beRepaired(1);
	two.beRepaired(1);
	two.beRepaired(1);
	two.beRepaired(1);
	two.beRepaired(1);
	two.beRepaired(1);
	two.setAttackDamage(10);
	two.attack(two.getName());
	one.takeDamage(10);
	two.attack(two.getName());
	three.guardGate();
	four.guardGate();
	four.attack(two.getName());
	two.takeDamage(20);
	std::cout << "A FragTrap appears!" << std::endl;
	FragTrap five("Lars");
	five.highFivesGuys();
	return 0;
}