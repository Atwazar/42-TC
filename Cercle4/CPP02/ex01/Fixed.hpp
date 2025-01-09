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
		Fixed &operator=(const Fixed&);
		Fixed(const Fixed&);
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

