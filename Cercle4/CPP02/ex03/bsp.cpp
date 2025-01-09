/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:23:18 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/16 15:23:20 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed zero;
	Fixed first_delta = Point::Z_component(a, b, point);
	Fixed second_delta = Point::Z_component(b, c, point);
	Fixed third_delta = Point::Z_component(c, a, point);
	// std::cout << "first delta is " << first_delta << "\nsecond delta is "
	// << second_delta << "\nthird delat is "<< third_delta << std::endl;
	Fixed max = Fixed::max(first_delta, (Fixed::max(second_delta, third_delta)));
	Fixed min = Fixed::min(first_delta, (Fixed::min(second_delta, third_delta)));
	// std::cout << "max is " << max << "\nand min is "<< min << std::endl;
	if (min > zero || max < zero)
		return (true);
	return (false);
}
