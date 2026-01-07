/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:59:47 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/06 17:21:14 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

using std::cout;
using std::string;
using std::endl;
using std::getline;

int main(void)
{
	PhoneBook phonebook;
	string input;
	
	while (1)
	{
		cout << "Would you like to ADD, SEARCH or EXIT?" << endl;
		if (!getline(std::cin, input))
			return (0);
		if (input == "ADD")
		{
			if (phonebook.addContact() == -1)
				return (0);
		}
		else if (input == "SEARCH")
		{
			phonebook.displayTable();
			if (phonebook.displayContact() == -1)
				return (0);
		}
		else if (input == "EXIT")
			return (0);
	}
}
