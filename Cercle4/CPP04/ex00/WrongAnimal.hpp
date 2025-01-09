/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:36:57 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 12:36:58 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP

# define WrongAnimal_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		virtual ~WrongAnimal(void);
		WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal&);
		WrongAnimal(const WrongAnimal&);
		void makeSound() const;
	protected:
		std::string _type;
};

#endif
