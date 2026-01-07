/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:26:10 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/07 12:04:15 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(){
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "KETCHUP", "MAYO"};
	Harl harl;
	for (size_t i = 0; i < 6; i++)
	{
		int j = i % 6;
		harl.complain(levels[j]);
		cout << std::endl;
	}
	return 0;
}