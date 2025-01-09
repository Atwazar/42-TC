/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:49:10 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/14 17:49:11 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed = 0;
}

Fixed::Fixed(const Fixed& Fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed = Fixed.getRawBits();
}
Fixed &Fixed::operator=(const Fixed& Fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed = Fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->fixed);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed = raw;
}
