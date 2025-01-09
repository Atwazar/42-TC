/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:23:54 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/12 15:23:56 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		for (size_t j = 0; j < strlen(av[i]); j++)
			av[i][j] = toupper(av[i][j]);
		std::cout << av[i];
	}
	if (ac == 1)
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
	return (1);
}
