/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:26:35 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/27 17:07:22 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fp_number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : fp_number(value << fractional_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : fp_number(roundf(value * (1 << fractional_bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : fp_number(other.fp_number){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fp_number = other.fp_number;
	return *this;
}

bool Fixed::operator<(const Fixed& other) {
	return (fp_number < other.fp_number);
}
bool Fixed::operator>(const Fixed& other) {
	return (fp_number > other.fp_number);
}
bool Fixed::operator==(const Fixed& other) {
	return (fp_number == other.fp_number);
}
bool Fixed::operator>=(const Fixed& other) {
	return (fp_number >= other.fp_number);
}
bool Fixed::operator<=(const Fixed& other) {
	return (fp_number <= other.fp_number);
}
bool Fixed::operator!=(const Fixed& other) {
	return (fp_number != other.fp_number);
}
Fixed Fixed::operator+(const Fixed& other) const {
	Fixed add;
	add.setRawBits(fp_number + other.fp_number);
	return add;
}
int Fixed::operator-(const Fixed& other) {
	return (fp_number - other.fp_number);
}
int Fixed::operator*(const Fixed& other) {
	return (fp_number * other.fp_number);
}
int Fixed::operator/(const Fixed& other) {
	return (fp_number / other.fp_number);
}
const Fixed& Fixed::operator++() {
	fp_number++;
	return (*this);
}
const Fixed Fixed::operator++(int) {
	Fixed tmp(fp_number);
	operator++();
	return (tmp);
}
const Fixed& Fixed::operator--() {
	if (fp_number >= 2)
	{
		fp_number--;
	}
	return (*this);
}
const Fixed Fixed::operator--(int) {
	Fixed tmp(fp_number);
	operator--();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fp_number;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	fp_number = raw;
}

float Fixed::toFloat( void ) const {
	return ((float)fp_number / (1 << fractional_bits));
}

int Fixed::toInt( void ) const {
	return (fp_number / (1 << fractional_bits));
}
