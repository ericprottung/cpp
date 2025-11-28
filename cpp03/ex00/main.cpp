/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:28:13 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/28 14:46:42 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
	return 0;
}