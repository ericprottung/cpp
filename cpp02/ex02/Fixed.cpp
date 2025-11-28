/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:26:35 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/28 13:22:58 by eprottun         ###   ########.fr       */
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
bool Fixed::operator<(const Fixed& other) const {
	return (fp_number < other.fp_number);
}
bool Fixed::operator>(const Fixed& other) const {
	return (fp_number > other.fp_number);
}
bool Fixed::operator==(const Fixed& other) const {
	return (fp_number == other.fp_number);
}
bool Fixed::operator>=(const Fixed& other) const {
	return (fp_number >= other.fp_number);
}
bool Fixed::operator<=(const Fixed& other) const {
	return (fp_number <= other.fp_number);
}
bool Fixed::operator!=(const Fixed& other) const {
	return (fp_number != other.fp_number);
}
Fixed Fixed::operator+(const Fixed& other) const {
	Fixed add;
	add.setRawBits(fp_number + other.fp_number);
	return add;
}
Fixed Fixed::operator-(const Fixed& other) const {
	Fixed sub;
	sub.setRawBits(fp_number - other.fp_number);
	return sub;
}
Fixed Fixed::operator*(const Fixed& other) const {
	Fixed mul(this->toFloat() * other.toFloat());
	return mul;
}
Fixed Fixed::operator/(const Fixed& other) const {
	Fixed div(this->toFloat() / other.toFloat());
	return div;
}
Fixed& Fixed::operator++() {
	fp_number++;
	return (*this);
}
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->operator++();
	return tmp;
}
Fixed& Fixed::operator--() {
	fp_number--;
	return (*this);
}
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return (tmp);
}
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits( void ) const {
	return fp_number;
}
void Fixed::setRawBits( int const raw ) {
	fp_number = raw;
}
float Fixed::toFloat( void ) const {
	return ((float)fp_number / (1 << fractional_bits));
}
int Fixed::toInt( void ) const {
	return (fp_number / (1 << fractional_bits));
}
const Fixed& Fixed::min(const Fixed& nr1, const Fixed& nr2) {
	return nr2 < nr1 ? nr2 : nr1;
}
Fixed& Fixed::min(Fixed& nr1, Fixed& nr2) {
	return nr2 < nr1 ? nr2 : nr1;
}
const Fixed& Fixed::max(const Fixed& nr1, const Fixed& nr2) {
	return nr2 > nr1 ? nr2 : nr1;
}
Fixed& Fixed::max(Fixed& nr1, Fixed& nr2) {
	return nr2 > nr1 ? nr2 : nr1;
}
