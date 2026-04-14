/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:28:13 by eprottun          #+#    #+#             */
/*   Updated: 2026/02/26 20:51:33 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main () {
	ClapTrap one("John");
	ClapTrap two("Samuel");
	
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
	return 0;
}