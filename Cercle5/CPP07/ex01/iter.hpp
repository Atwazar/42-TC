/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:45:39 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/23 17:49:01 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void iter(T *array, int length, void f(T &))
{
	for (int i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void iter(const T *array, int length, void f(T &))
{
	for (int i = 0; i < length; i++)
		f(const_cast<T&>(array[i]));
}
