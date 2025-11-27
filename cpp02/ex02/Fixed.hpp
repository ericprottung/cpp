/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:53:45 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/27 17:07:20 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>


class Fixed {
	public :
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		bool operator<(const Fixed& other);
		bool operator>(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator>=(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator!=(const Fixed& other);
		const Fixed& operator++();
		const Fixed operator++(int);
		const Fixed& operator--();
		const Fixed operator--(int);
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		const int& min(const Fixed& nr1, const Fixed& nr2);
	private :
		int fp_number;
		static const int fractional_bits = 8;
	}	;
	
#endif