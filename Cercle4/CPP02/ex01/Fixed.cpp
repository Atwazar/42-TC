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
#include <math.h>

const int Fixed::rawbit = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed = 0;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Integer constructor called" << std::endl;
	this->fixed = (integer << this->rawbit);
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed = int(roundf(number * (1 << this->rawbit)));
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
	return(this->fixed);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed = raw;
}

float Fixed::toFloat(void) const
{
	return (float(this->fixed) / (1 << this->rawbit));
}

int Fixed::toInt(void) const
{
	return (this->fixed >> this->rawbit);
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return (o);
}
