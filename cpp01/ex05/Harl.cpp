/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:28:22 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/26 19:07:10 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ) {
	cout << "I love having extra bacon for my 7XL-double-\
cheese-triple-pickle-special-ketchup burger. \
I really do!" << endl;
}
void Harl::info( void ) {
	cout << "I cannot believe adding extra bacon \
costs more money. You didn’t put enough bacon in my burger! \
If you did, I wouldn’t be asking for more!" << endl;
}
void Harl::warning( void ) {
	cout << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years, whereas you started working \
here just last month." << endl;
}
void Harl::error( void ) {
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

void Harl::complain( std::string level ) {
	void(Harl::*functionptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	(this->*functionptr[(level[0] & 1) + ((level[0] & 0b101) == 0b101) * (!((level[0] & 0b10) >> 1) + 1)])();
}
