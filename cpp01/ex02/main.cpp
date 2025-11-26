/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:49:51 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/26 11:03:02 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::string;

int main() {
	string str = "HI THIS IS BRAIN";
	
	string* stringPTR = &str;
	string& stringREF = str;

	cout << &str << std::endl;
	cout << stringPTR << std::endl;
	cout << &stringREF << std::endl;

	cout << str << std::endl;
	cout << *stringPTR << std::endl;
	cout << stringREF << std::endl;
	
	return 0;
}