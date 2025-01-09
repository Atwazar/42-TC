/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:45:39 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/23 17:49:01 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>

template <typename T> void swap(T &a, T &b)
{
	T temporary = a;

	a = b;
	b = temporary;
}

template <typename T> T max(T a, T b)
{
	return (a > b ? a : b);
}

template <typename T> T min(T a, T b)
{
	return (a < b ? a : b);
}
