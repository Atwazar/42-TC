/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:45:39 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/23 17:49:01 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	{
	int a = 1;
	int b = 2;

	std::cout << "a = " << a << " and b= " << b << std::endl;
	::swap(a, b);
	std::cout << "swapping..." << std:: endl;
	std::cout << "a = " << a << " and b= " << b << std::endl;
	std::cout << "max(a,b) is " << ::max(a,b) << " and min (a,b) is " << ::min(a,b) << std::endl;
	}
	{
	char a = 'c';
	char b = 'd';
	std::cout << "a = " << a << " and b= " << b << std::endl;
	std::cout << "swapping..." << std:: endl;
	::swap(a, b);
	std::cout << "a = " << a << " and b= " << b << std::endl;
	std::cout << "max(a,b) is " << ::max(a,b) << " and min (a,b) is " << ::min(a,b) << std::endl;
	}
	{
	std::string a = "bonjour";
	std::string b = "salut a va bien";
	std::cout << "a = " << a << " and b= " << b << std::endl;
	std::cout << "swapping..." << std:: endl;
	::swap(a, b);
	std::cout << "a = " << a << " and b= " << b << std::endl;
	std::cout << "max(a,b) is " << ::max(a,b) << " and min (a,b) is " << ::min(a,b) << std::endl;
	}
}
