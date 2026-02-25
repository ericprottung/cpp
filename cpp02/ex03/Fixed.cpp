/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:26:35 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/14 17:09:58 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fpNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value) : fpNumber(value << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float value) : fpNumber(roundf(value * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other) : fpNumber(other.fpNumber){
	std::cout << "Copy constructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fpNumber = other.fpNumber;
	return *this;
}
bool Fixed::operator<(const Fixed& other) const {
	return (fpNumber < other.fpNumber);
}
bool Fixed::operator>(const Fixed& other) const {
	return (fpNumber > other.fpNumber);
}
bool Fixed::operator==(const Fixed& other) const {
	return (fpNumber == other.fpNumber);
}
bool Fixed::operator>=(const Fixed& other) const {
	return (fpNumber >= other.fpNumber);
}
bool Fixed::operator<=(const Fixed& other) const {
	return (fpNumber <= other.fpNumber);
}
bool Fixed::operator!=(const Fixed& other) const {
	return (fpNumber != other.fpNumber);
}
Fixed Fixed::operator+(const Fixed& other) const {
	Fixed add;
	add.setRawBits(fpNumber + other.fpNumber);
	return add;
}
Fixed Fixed::operator-(const Fixed& other) const {
	Fixed sub;
	sub.setRawBits(fpNumber - other.fpNumber);
	return sub;
}
Fixed Fixed::operator*(const Fixed& other) const {
	Fixed mul(toFloat() * other.toFloat());
	return mul;
}
Fixed Fixed::operator/(const Fixed& other) const {
	Fixed div(toFloat() / other.toFloat());
	return div;
}
Fixed& Fixed::operator++() {
	fpNumber++;
	return (*this);
}
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}
Fixed& Fixed::operator--() {
	fpNumber--;
	return (*this);
}
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return (tmp);
}
Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits( void ) const {
	return fpNumber;
}
void Fixed::setRawBits( int const raw ) {
	fpNumber = raw;
}
float Fixed::toFloat( void ) const {
	return ((float)fpNumber / (1 << fractionalBits));
}
int Fixed::toInt( void ) const {
	return (fpNumber / (1 << fractionalBits));
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
std::ostream& operator<<(std::ostream& os, Fixed const& fixed){
	os << fixed.toFloat();
	return os;
}
