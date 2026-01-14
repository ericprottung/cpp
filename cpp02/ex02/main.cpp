/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:56:31 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/14 17:03:31 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Fixed const& fixed){
	os << fixed.toFloat();
	return os;
}
	
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << std::endl;
std::cout << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::min( a, b ) << std::endl;
std::cout << Fixed::min( --a, b ) << std::endl;
std::cout << Fixed::min( ++a, b ) << std::endl;
std::cout << std::endl;
std::cout << std::endl;
std::cout << a << " is a" << std::endl;
std::cout << b << " is b" << std::endl;
std::cout << Fixed::min( a, b) << " is min" << std::endl;
std::cout << std::endl;
std::cout << std::endl;
Fixed c(3.5f);
c = c * Fixed(10);
c = c * Fixed(10);
std::cout << c << " is c" << std::endl;
c = c / Fixed(10);
c = c / Fixed(10);
std::cout << c << " is c" << std::endl;
return 0;
}
