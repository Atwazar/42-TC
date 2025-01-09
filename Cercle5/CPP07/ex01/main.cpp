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

#include "iter.hpp"

static void test_working(std::string &test)
{
	test = test + "_alright";
}

static void test_working_2(int &i)
{
	i = i + 2;
}

template <typename T>
void testing(T *array, int length, void f(T &))
{
	std::cout << "tab before change" << std::endl;
	for (int i = 0; i < length; i++)
		std::cout << array[i] << "|";
	std::cout << std::endl;
	::iter(array, length, f);
	std::cout << "tab after change" << std::endl;
	for (int i = 0; i < length; i++)
		std::cout << array[i] << "|";
	std::cout << std::endl << std::endl;
}

int main(void)
{
	std::cout << "test with string" << std::endl;
	{
	std::string test_array[] = {"hey", "how", "are", "you", ""};
	int length = 5;
	testing(test_array, length, test_working);
	}
	{
	int test_int_array[] ={1, 2, 3, 4, 5, 6};
	int length = 6;
	testing(test_int_array, length, test_working_2);
	}
}
