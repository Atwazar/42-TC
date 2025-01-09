/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:35:43 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 12:35:44 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP

# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
	public:
		~Cat(void);
		Cat();
		Cat &operator=(const Cat&);
		Cat(const Cat&);
		void makeSound() const;
	private:
		Brain	*_brain;
};

#endif
