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
#include "Point.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Fixed const& fixed){
	os << fixed.toFloat();
	return os;
}
	
int main( void ) {
    Point a(2, 0);
    Point b(0, 2);
    Point c(0, 0);
    Point test(1, 0.2);
    std::cout << std::endl << bsp(a, b, c, test) << std::endl;
    Point d(2, 0);
    Point e(0, 2);
    Point f(0, 0);
    Point testo(1, 1);
    std::cout << std::endl << bsp(d, e, f, testo) << std::endl;
    Point g(2, 0);
    Point h(0, 2);
    Point i(0, 0);
    Point testinho(0.99, 0.99);
    std::cout << std::endl << bsp(g, h, i, testinho) << std::endl;
    return 0;
}
