/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:35:55 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 12:35:56 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP

# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
	public:
		~Dog(void);
		Dog();
		Dog &operator=(const Dog&);
		Dog(const Dog&);
		void makeSound() const;

	private:
		Brain	*_brain;
};

#endif
