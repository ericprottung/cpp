/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:56:12 by eprottun          #+#    #+#             */
/*   Updated: 2026/03/01 19:20:41 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* l = new Cat(*static_cast<const Cat *>(i));
	Cat *one = new Cat();
	Cat *two = new Cat();
	const WrongAnimal* k = new WrongCat();
	WrongCat test;

	std::cout << "\n\n<<<<<<<<<<< 1.   getType and makeSound comparison >>>>>>>>>>>>>\n\n";
	std::cout << j->getType() << std::endl;
	j->makeSound();
	std::cout << i->getType() << std::endl;
	i->makeSound();
	std::cout << l->getType() << std::endl;
	l->makeSound();
	std::cout << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << k->getType() << std::endl;
	k->makeSound();
	std::cout << test.getType() << std::endl;
	test.makeSound();
	std::cout << std::endl;
	
	std::cout << "\n\n<<<<<<<<<<< 2. subject test >>>>>>>>>>>>>\n\n";
	Animal *array[100];
	for (unsigned int i = 0 ; i < 99 ; i += 2) {
	    array[i] = new Dog();
	    array[i + 1] = new Cat();
	}
	std::cout << "\n\n<<<<<<<<<<< 3. deep copy test >>>>>>>>>>>>>\n\n";
	one->printIdeas();
	one->setIdea("fiiiiight", 2);
	std::cout << std::endl;
	two->printIdeas();
	*two = *one;
	std::cout << "\nideas of cat two must have fiiiight at 2\n";
	two->printIdeas();
	std::cout << "\nnow original one gets deleted\n";
	delete one;
	std::cout << "\nshould still have fiiiight\n";
	two->printIdeas();
	Cat copycat(*two);
	delete two;
	std::cout << "\ncopycat should print\n";
	copycat.printIdeas();
	delete meta;
	delete j;
	delete i;
	delete l;
	delete k;
	std::cout << "\nnow the deletion starts\n";
	for (unsigned int i = 0; i < 100 ; ++i)
	    delete array[i];
	return 0;
}
