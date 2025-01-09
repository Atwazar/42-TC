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

#include "Array.hpp"
#include <iostream>
#include <cstdlib>

#define MAX_VAL 750

template <typename T>
void print(Array<T> array)
{
	unsigned int size = array.size();
	std::cout << "printing array of size " << size << std::endl;
	for (unsigned int i = 0; i < size; i++)
		std::cout << "|" << array[i];
	std::cout << std::endl;
}

int main(void)
{
	{
	Array<int> test_int;
	try
	{
		int c = test_int[2];

		std::cout << c << " this shouldn't be displayed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout <<" this should be displayed" << std::endl;
	}
	print(test_int);
	test_int = Array<int>(12);
	print(test_int);
	test_int[11] = 12;
	print(test_int);
	Array<int> test_int_2(test_int);
	print(test_int_2);

	Array<std::string> test_string(10);
	print(test_string);
	test_string[1] = "salut ca va bien";
	print(test_string);
	}
	{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
}
