/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:49:02 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/16 15:23:33 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Point_H
# define Point_H

#include <string>
#include <iostream>
#include <math.h>
#include "Fixed.hpp"

class Point {
	public:
		~Point(void);
		Point(void);
		Point(float x, float y);
		Point(const Point&);
		Point &operator=(const Point&);

		static Fixed Z_component(const Point &a,const Point &b,const Point &m);
		Fixed get_x(void) const;
		Fixed get_y(void) const;

	private:
		const Fixed x;
		const Fixed y;
};

std::ostream& operator<<(std::ostream& o, const Point& Point);

#endif

