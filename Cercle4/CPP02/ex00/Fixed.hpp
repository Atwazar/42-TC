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

class Fixed {
	public:
		~Fixed(void);
		Fixed(void);
		Fixed &operator=(const Fixed&);
		Fixed(const Fixed&);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int	fixed;
		static const int rawbit = 8;
};
#endif

