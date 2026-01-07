/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:33:42 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/06 17:07:28 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	public:
		int	addContact();
		void displayTable();
		int displayContact();
		PhoneBook();
	private:
		int	getIndex(int amount);
		size_t	total_entries;
		Contact contacts[8];
} ;

#endif