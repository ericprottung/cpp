/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:33:42 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/20 15:16:41 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact {
	public:
		std::string get_first_name(void);
		std::string get_last_name(void);
		std::string get_nick_name(void);
		std::string get_phone_number(void);
		std::string get_darkest_secret(void);
		int setField(const std::string &prompt, std::string &field);
		int setInfo() {
			if (setField("FIRST NAME: ", first_name) == -1) return -1;
			if (setField("LAST NAME: ", last_name) == -1) return -1;
			if (setField("NICK NAME: ", nick_name) == -1) return -1;
			if (setField("PHONE NUMBER: ", phone_number) == -1) return -1;
			if (setField("DARKEST SECRET: ", darkest_secret) == -1) return -1;
			return 0;
		}
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
} ;

class PhoneBook {
	public:
		int	addContact();
		void displayTable();
		int displayContact();
		PhoneBook() {
    		total_entries = 0;
		}
	private:
		size_t	total_entries;
		Contact contacts[8];
} ;
