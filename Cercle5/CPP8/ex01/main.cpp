/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:24:56 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/26 17:24:57 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <list>

int *random_list_generator(int N)
{
	int* tab = new int[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        const int value = rand() % 100;
        tab[i] = value;
    }
	return (tab);
}

int main(void)
{
	srand((unsigned int)time(0));
	{
	std::cout << "testing capacity" << std::endl;
	Span span(1);
	std::cout << span << std::endl;
	span.addNumber(19);
	std::cout << span << std::endl;
	try
	{
		span.addNumber(2);
		std::cout << span << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	Span span_2(span);
	std::cout << span_2 << std::endl;
	try
	{
		span_2.addNumber(2);
		std::cout << span << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	}
	{
	std::cout << "testing generator" << std::endl;
	int N = 20;
	Span span(N);
	try
	{
		span.addList(random_list_generator(N), N);
		std::cout << span << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	}
	{
		std::cout << "testing short span and long span" << std::endl;
		int N = 20;
		Span span(N);
	try
	{
		span.addList(random_list_generator(N), N);
		std::cout << span << std::endl;
		std::cout << "shortest span is " << span.shortestSpan() << " and longest span is " << span.longestSpan()<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	}
}
