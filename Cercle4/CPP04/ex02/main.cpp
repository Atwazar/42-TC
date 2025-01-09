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
	const Dog* doggy = new Dog();
	Dog doggy_2 = Dog(*doggy);
	Dog doggy_3;
	doggy_3 = doggy_2;
	delete doggy;
	const Cat* cathy = new Cat();
	Cat cathy_2 = Cat(*cathy);
	Cat cathy_3 = cathy_2;
	delete cathy;
	// const Animal* Animaly = new Animal();
	return 0;
}
