/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:36:22 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 12:36:23 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP

# define WrongCat_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		~WrongCat(void);
		WrongCat();
		WrongCat &operator=(const WrongAnimal&);
		WrongCat(const WrongAnimal&);
		void makeSound() const;
};

#endif
