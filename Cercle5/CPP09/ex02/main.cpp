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

#include "PmergeMe.hpp"

#define LIMIT_WITHOUT_USING_SUIT 4

static int Weird_suit(int n)
{
	if (n == 0)
		return 2;

	if (n == 1)
		return 2;

	return pow(2, (n + 1)) - Weird_suit(n - 1);
}

static int *create_array(int ac)
{
	int middle = ac%2? (ac + 1)/2 : ac/2;
	middle -= 2;
	int *suit = new int[middle];
	for (int i = 0; i < middle; i++)
		suit[i] = i + 3;
	int *weird_suit = new int[middle + 1];
	int total_number_added = 0;
	int saved_number = 0;
	int weird_suit_value;
	int i = 0;
	int number_selected;
	while (total_number_added < middle)
	{
		weird_suit_value = Weird_suit(i);

		while (weird_suit_value)
		{
			number_selected = saved_number + weird_suit_value - 1;
			if (number_selected < middle)
				weird_suit[total_number_added++] = suit[number_selected];
			weird_suit_value--;
		}
		saved_number += Weird_suit(i);
		i++;
	}
	weird_suit[total_number_added] = 0;
	delete[] suit;
	return weird_suit;
}



static int is_appropriate_number(std::string nbr)
{
	for (unsigned long i = 0; i < nbr.length(); i++)
	{
		if (!isdigit(nbr[i]))
		{
			std::cout << "Error: the arg: \'" << nbr << "\' is not only made of digits" << std::endl;
			return (BAD_NUMBER);
		}
	}
	long nbr_l = atol(nbr.c_str());
	if (nbr_l > INT_MAX)
	{
		std::cout << "Error: the arg: \'" << nbr << "\' is too big for an int" << std::endl;
		return (BAD_NUMBER);
	}
	return static_cast<int>(nbr_l);
}

static int *check_args(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Error: at least one argument is required" << std::endl;
		return NULL;
	}
	int *number_array = new int[ac -1];
	for (int i = 1; i < ac; i++)
	{
		int nbr = is_appropriate_number(av[i]);
		if (nbr == BAD_NUMBER)
		{
			delete[] number_array;
			return NULL;
		}
		number_array[i -1] = nbr;
	}
	return number_array;

}
int main(int ac, char **av)
{
	int *number_array = check_args(ac, av);
	if (!number_array)
		return (1);
	int *weird_array = NULL;
	if (ac - 1 > LIMIT_WITHOUT_USING_SUIT)
	{
		weird_array = create_array(ac - 1);
		for (int i = 0; weird_array[i] != 0; i++)
		{
			std::cout << weird_array[i] << " ";
		}
		std::cout << std::endl;
	}

	merge_insert_vect(number_array, ac, weird_array);
	merge_insert_list(number_array, ac, weird_array);
	if (ac - 1> LIMIT_WITHOUT_USING_SUIT)
		delete[] weird_array;
	delete[] number_array;
	return (0);
}
