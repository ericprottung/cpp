/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:28:22 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/07 12:13:48 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ) {
	cout << "[DEBUG]" << endl;
	cout << "I love having extra bacon for my 7XL-double-\
cheese-triple-pickle-special-ketchup burger. \
I really do!" << endl;
}
void Harl::info( void ) {
	cout << "[INFO]" << endl;
	cout << "I cannot believe adding extra bacon \
costs more money. You didn’t put enough bacon in my burger! \
If you did, I wouldn’t be asking for more!" << endl;
}
void Harl::warning( void ) {
	cout << "[WARNING]" << endl;
	cout << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years, whereas you started working \
here just last month." << endl;
}
void Harl::error( void ) {
	cout << "[ERROR]" << endl;
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

void Harl::complain( std::string level ) {
	void(Harl::*functionptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i;
	i = 0;
	if (!level.compare("DEBUG"))
		i = 1;
	else if (!level.compare("INFO"))
		i = 2;
	else if (!level.compare("WARNING"))
		i = 3;
	else if (!level.compare("ERROR"))
		i = 4;
	switch (i) {
		case 1: (this->*functionptr[0])();
		case 2: (this->*functionptr[1])();
		case 3: (this->*functionptr[2])();
		case 4: (this->*functionptr[3])();
		break;
		default : cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
