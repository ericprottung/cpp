/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:38:33 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/07 11:13:07 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

const string& Contact::get_first_name() const {
	return (this->first_name);
}

const string& Contact::get_last_name() const {
	return (this->last_name);
}

const string& Contact::get_nick_name() const {
	return (this->nick_name);
}

const string& Contact::get_phone_number() const {
	return (this->phone_number);
}

const string& Contact::get_darkest_secret() const {
	return (this->darkest_secret);
}

int Contact::setField(const string &prompt, string &field)
{
	std::string input;
	
	cout << prompt;
	if (!getline(cin, input))
		return (cout << endl, -1);
	while (input.empty())
	{
		cout << "Input empty! Try again: ";
		if (!getline(cin, input))
			return (cout << endl, -1);
	}
	field = input;
	return (0);
}

int Contact::setInfo() {
	if (setField("FIRST NAME: ", first_name) == -1) return -1;
	if (setField("LAST NAME: ", last_name) == -1) return -1;
	if (setField("NICK NAME: ", nick_name) == -1) return -1;
	if (setField("PHONE NUMBER: ", phone_number) == -1) return -1;
	if (setField("DARKEST SECRET: ", darkest_secret) == -1) return -1;
	return 0;
}
