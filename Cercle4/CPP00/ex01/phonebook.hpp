/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:26:08 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/12 16:28:44 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(); //Constructor Declaration
		PhoneBook(const PhoneBook&); // Copy declaration
		~PhoneBook (); // Destructor declaration
		PhoneBook &operator=(const PhoneBook&); // = declaration
		void add_contact();
		void search_contact();
		int		invalid_phone_number(std::string s);
		void fill_test(); //test function
		private:
			Contact contacts[8]; //Attributes
			int		len; //Attributes

};

#endif
