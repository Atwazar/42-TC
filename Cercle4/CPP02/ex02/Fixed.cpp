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
//For canonical sake
Fixed::Fixed(void)
{
	this->fixed = 0;
}

Fixed::Fixed(const int integer)
{
	this->fixed = (integer << this->rawbit);
}

Fixed::Fixed(const float number)
{
	this->fixed = int(roundf(number * (1 << this->rawbit)));
}

Fixed::Fixed(const Fixed& Fixed)
{
	this->fixed = Fixed.getRawBits();
}
Fixed &Fixed::operator=(const Fixed& Fixed)
{
	this->fixed = Fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
}

//Comparaison operator
int Fixed::operator>(const Fixed& b) const
{
	return (this->toFloat() > b.toFloat());
}

int Fixed::operator<(const Fixed& b) const
{
	return (this->toFloat() < b.toFloat());
}

int Fixed::operator>=(const Fixed& b) const
{
	return (this->toFloat() >= b.toFloat());
}

int Fixed::operator<=(const Fixed& b) const
{
	return (this->toFloat() <= b.toFloat());
}

int Fixed::operator==(const Fixed& b) const
{
	return (this->toFloat() == b.toFloat());
}

int Fixed::operator!=(const Fixed& b) const
{
	return (this->toFloat() != b.toFloat());
}

//Arithmetic operator
Fixed Fixed::operator+(const Fixed& b) const
{
	return (Fixed(this->toFloat() + b.toFloat()));
}

Fixed Fixed::operator-(const Fixed& b) const
{
	return (Fixed(this->toFloat() - b.toFloat()));
}

Fixed Fixed::operator*(const Fixed& b) const
{
	return (Fixed(this->toFloat() * b.toFloat()));
}

Fixed Fixed::operator/(const Fixed& b) const
{
	return (Fixed(this->toFloat() / b.toFloat()));
}

//Increment/decrement operator
Fixed Fixed::operator++()
{
	this->fixed++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed b(*this);
	++*this;
	return (b);
}
Fixed Fixed::operator--()
{
	this->fixed--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed b(*this);
	--*this;
	return (b);
}

//min/max functions

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed&a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed&a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}
//Usefull function
int Fixed::getRawBits(void) const
{
	return(this->fixed);
}

void Fixed::setRawBits(int const raw)
{
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
