/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:15:38 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/16 15:15:41 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Character_HPP

# define Character_HPP

# include "AMateria.hpp"
# include <string>

class Character : public ICharacter
{
	public:
		Character(std::string type);
		Character();
		~Character(void);
		Character &operator=(const Character&);
		Character(const Character&);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria* access_inventory(int idx);
	private:
		std::string _name;
		AMateria* _inventory[4];



};

#endif
