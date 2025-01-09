/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:26:08 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/12 16:28:44 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "include.hpp"

class Contact
{
	public:
		~Contact(); // Destructor declaration
		Contact &operator= (const Contact&); // = declaration
		Contact();
		Contact(const std::string first_name,
		const std::string last_name,
		const std::string nick_name,
		const std::string phone_number,
		const std::string darkest_secret); //Constructor Declaration
		Contact(const Contact&); // Copy declaration
		void print_contact();
		std::string get_first();
		std::string get_nick();
		std::string get_last();
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
};

#endif
