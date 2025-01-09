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

#ifndef CURE_HPP

# define CURE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		virtual ~Cure();
		Cure();
		Cure &operator=(const Cure&);
		Cure(const Cure&);

		std::string const & getType() const;
		Cure* clone() const;
		void use(ICharacter& target);
	protected:
		std::string type;
};

#endif
