/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:33:32 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/20 15:14:12 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

using std::cout;
using std::getline;
using std::string;
using std::endl;

int	PhoneBook::addContact() {
	Contact	add;
	
	if (add.setInfo() == -1)
		return (-1);
	this->contacts[this->total_entries % 8] = add;
	this->total_entries++;
	cout << endl;
	return (0);
}

static void	print_cell(string content) {
	if (content.size() <= 10)
	{
		for (size_t i = 0; i < 10 - content.size(); i++)
			cout << " ";
		cout << content << "|";
	}
	else
	{
		cout << content.substr(0, 9) << ".|";
	}
}

void	PhoneBook::displayTable() {
	size_t amount = 8;
	
	if (this->total_entries < 8)
		amount = this->total_entries;
	cout << "---------------------------------------------" << endl;
	for (size_t i = 0; i < amount; i++)
	{
		cout << "|    " << i << "     |";
		print_cell(contacts[i].get_first_name());
		print_cell(contacts[i].get_last_name());
		print_cell(contacts[i].get_nick_name());
		cout << endl << "---------------------------------------------" << endl;
	}
	cout << endl;
}

static int	getIndex(int amount) {
	string input;

	cout << "Enter index for contact information: ";
	if (!getline(std::cin, input))
		return (cout << endl, -1);
	cout << endl;
	while (!(input.size() == 1 && input[0] >= '0' && input[0] < '0' + amount))
	{
		cout << "Index not available! Try again: ";
		if (!getline(std::cin, input))
			return (cout << endl, -1);
	}
	return (input[0] - '0');
}

int	PhoneBook::displayContact() {
	size_t amount = 8;
	
	if (this->total_entries == 0)
	{
		cout << "No contacts found!" << endl;
		return (0);
	}
	if (this->total_entries < 8)
		amount = this->total_entries;
	int index = getIndex(amount);
	if (index == -1)
		return (-1);
	cout << "FIRST NAME: " << this->contacts[index].get_first_name() << endl;
	cout << "LAST NAME: " << this->contacts[index].get_last_name() << endl;
	cout << "NICK NAME: " << this->contacts[index].get_nick_name() << endl;
	cout << "PHONE NUMBER: " << this->contacts[index].get_phone_number() << endl;
	cout << "DARKEST SECRET: " << this->contacts[index].get_darkest_secret() << endl;
	cout << endl;
	return (0);
}

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
		else
			cout << endl << "Input not valid!" << endl << endl;
	}
	return (0);
}