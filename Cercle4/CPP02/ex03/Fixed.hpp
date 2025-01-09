/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:49:02 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/14 17:49:03 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <string>
#include <iostream>
#include <math.h>

class Fixed {
	public:
		~Fixed(void);
		Fixed(void);
		Fixed(const float number);
		Fixed(const int integer);
		Fixed(const Fixed&);
		Fixed &operator=(const Fixed&);

		//Comparaison operator
		int operator>(const Fixed&) const;
		int operator<(const Fixed&) const;
		int operator>=(const Fixed&) const;
		int operator<=(const Fixed&) const;
		int operator==(const Fixed&) const;
		int operator!=(const Fixed&) const;
		//Arithmetic operator
		Fixed operator+(const Fixed&) const;
		Fixed operator-(const Fixed&) const;
		Fixed operator*(const Fixed&) const;
		Fixed operator/(const Fixed&) const;
		//increment/decrement operator
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);


		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed&a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed&a, const Fixed& b);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
	private:

		int	fixed;
		static const int rawbit;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif

