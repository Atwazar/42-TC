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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete(j);
	delete (i);
	delete (meta);
	const WrongAnimal* x = new WrongAnimal();
	x->makeSound();
	const WrongCat* y = new WrongCat();
	y->makeSound();
	const WrongAnimal* z = new WrongCat();
	z->makeSound();
	delete x;
	delete y;
	delete z;
	return 0;
}
