/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:49:10 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/16 15:23:26 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"
#include <math.h>

//For canonical sake
Point::Point(void):x(Fixed()),y(Fixed())
{
}

Point::Point(float x, float y):x(Fixed(x)),y(Fixed(y))
{
}

Point::Point(const Point& Point):x(Point.x),y(Point.y)
{
}

Point &Point::operator=(const Point& Point)
{
	return (*this);
}

Point::~Point(void)
{
}


//Usefull function
Fixed Point::get_x(void) const
{
	Fixed x = Fixed(this->x);
	return (x);
}

Fixed Point::get_y(void) const
{
	Fixed y = Fixed(this->y);
	return (y);
}

Fixed Point::Z_component(const Point &a,const Point &b, const Point &m)
{

	Fixed result = Fixed(((a.get_x() - m.get_x()) * (b.get_y() - m.get_y()))
	- ((a.get_y() - m.get_y()) * (b.get_x() - m.get_x())));
	return (result);
}



std::ostream& operator<<(std::ostream& o, const Point& Point)
{
	o << "x:" << Point.get_x().toFloat() << " y:"
	<< Point.get_y().toFloat();
	return (o);
}
