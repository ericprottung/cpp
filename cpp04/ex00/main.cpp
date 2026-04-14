/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:56:12 by eprottun          #+#    #+#             */
/*   Updated: 2026/03/01 18:11:58 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* l = new Cat(*static_cast<const Cat *>(i));
	Cat one;
	Cat two;
	one = two;
	const WrongAnimal* k = new WrongCat();
	WrongCat test;

	std::cout << "\n<<<<<<<<<<< getType and makeSound comparison >>>>>>>>>>>>>\n";
	std::cout << j->getType() << std::endl;
	j->makeSound();
	std::cout << i->getType() << std::endl;
	i->makeSound();
	std::cout << l->getType() << std::endl;
	l->makeSound();
	std::cout << "\nmeta animal\n";
	meta->makeSound();
	std::cout << k->getType() << std::endl;
	k->makeSound();
	std::cout << test.getType() << std::endl;
	test.makeSound();
	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;
	delete k;
	delete l;
	return 0;
}
