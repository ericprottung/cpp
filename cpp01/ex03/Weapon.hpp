/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:05:08 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/26 11:42:54 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon {
	public	:
		const std::string& get_type();
		void setType(std::string type);

		Weapon(std::string type) {
			this->type = type;
		}
	private	:
		std::string type;
	
}	;

#endif