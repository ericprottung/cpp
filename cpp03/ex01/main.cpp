/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:28:13 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/28 16:44:43 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	cout << one.getName() << " forgot to pick up his axe and takes it!" << endl;
	one.setAttackDamage(2);
	one.attack(two.getName());
	two.takeDamage(2);
	one.attack(two.getName());
	two.takeDamage(2);
	one.attack(two.getName());
	two.takeDamage(2);
	one.attack(two.getName());
	two.takeDamage(2);
	cout << two.getName() << " finally responds!" << endl;
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
	return 0;
}