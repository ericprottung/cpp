/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:56:31 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/28 13:07:16 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
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
Fixed c(5);
c = c * Fixed(10);
c = c * Fixed(10);
std::cout << c << " is c" << std::endl;
c = c / Fixed(10);
c = c / Fixed(10);
std::cout << c << " is c" << std::endl;
return 0;
}
