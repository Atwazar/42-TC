/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:05:06 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 13:05:08 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Dog dog;

	Dog doggy = dog;

	const Animal* list[100];
	for (int i = 0; i < 100; i++)
	{
		if (i%2)
			list[i] = new Dog();
		else
			list[i] = new Cat();
	}
	for (int i = 0; i < 100; i++)
	{
		delete (list[i]);
	}
}
