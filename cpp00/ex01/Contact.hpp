/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:51:39 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/06 17:19:25 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	public:
		const std::string& get_first_name(void) const;
		const std::string& get_last_name(void) const;
		const std::string& get_nick_name(void) const;
		const std::string& get_phone_number(void) const;
		const std::string& get_darkest_secret(void) const;
		int setField(const std::string &prompt, std::string &field);
		int setInfo();
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
} ;

#endif