/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:38:33 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/20 15:15:02 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

using std::cout;
using std::cin;
using std::string;
using std::endl;

string Contact::get_first_name() {
	return (this->first_name);
}

string Contact::get_last_name() {
	return (this->last_name);
}

string Contact::get_nick_name() {
	return (this->nick_name);
}

string Contact::get_phone_number() {
	return (this->phone_number);
}

string Contact::get_darkest_secret() {
	return (this->darkest_secret);
}

int Contact::setField(const string &prompt, string &field)
{
	std::string input;
	
	cout << prompt;
	if (!getline(std::cin, input))
		return (cout << endl, -1);
	while (input.empty())
	{
		cout << "Input empty! Try again: ";
		if (!getline(std::cin, input))
			return (cout << endl, -1);
	}
	field = input;
	return (0);
}
