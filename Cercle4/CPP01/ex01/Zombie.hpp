/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:49:02 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/14 17:49:03 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
	public:
	void announce (void);
	Zombie(std::string name);
	~Zombie(void);
	Zombie(void);
	Zombie &operator=(const Zombie&);
	Zombie(const Zombie&);
	void change_name(std::string name);

	private:
	std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif

