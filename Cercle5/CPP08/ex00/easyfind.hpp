/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:54:44 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/26 17:54:53 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <exception>
#include <iostream>

class NotFound: public std::exception{
};

template <typename T>
typename T::iterator easyfind(T& container, int to_find)
{
	typename T::iterator i = std::find(container.begin(), container.end(), to_find);
	if (i != container.end())
		return (i);
	// for (T::iterator i =  container.begin(); i!=container.end(); i.next())
	// {
	// 	if (*i == to_find)
	// 		return (i);
	// }
	throw NotFound();
}
