/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:35:38 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 12:35:39 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public:
		virtual ~Animal(void);
		Animal();
		Animal &operator=(const Animal&);
		Animal(const Animal&);
		virtual void makeSound() const;
	protected:
		std::string _type;
};

#endif
