/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:53:45 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/14 16:33:57 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <ostream>


class Fixed {
	public :
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		bool operator<(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static const Fixed& min(const Fixed& nr1, const Fixed& nr2);
		static Fixed& min(Fixed& nr1, Fixed& nr2);
		static const Fixed& max(const Fixed& nr1, const Fixed& nr2);
		static Fixed& max(Fixed& nr1, Fixed& nr2);
	private :
		int fpNumber;
		static const int fractionalBits = 8;
}	;

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);

#endif