/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:48:48 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/14 17:48:51 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

std::string	get_bool(bool answer)
{
	if (answer == true)
		return (" True");
	return (" False");
}

int main( void ) {
	Point a(0, 0);
	Point b(1, 0);
	Point c(0, 1);

	Point test1(0.5f, 0.2f);
	std::cout << "first point in triangle:" << get_bool(bsp(a, b, c, test1)) << std::endl;
	Point test2(0, 0);
	std::cout << "second point in triangle:" << get_bool(bsp(a, b, c, test2))<< std::endl;
	Point test3(200, 200);
	std::cout << "third point in triangle:" << get_bool(bsp(a, b, c, test3)) << std::endl;
	Point test4(0.5f, 0.49f);
	std::cout << "fourth point in triangle:" << get_bool(bsp(a, b, c, test4)) << std::endl;
}
