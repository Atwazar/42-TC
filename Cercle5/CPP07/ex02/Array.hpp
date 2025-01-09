/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:06:28 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/26 13:06:30 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define INVALID_INDEX "index call is invalid"

template <typename T>

class Array
{
	public:
		Array()
		{
			_array = new T[0] ;
			_size = 0;
		}
		Array(unsigned int n)
		{
			_array = new T[n];
			_size = n;
		}
		~Array()
		{
			delete[] _array;
		}
		Array(const Array& other)
		{
			_array = new T[other._size];
			_size = other._size;
			for (unsigned int i = 0; i < _size; i++)
			{
				_array[i] = other._array[i];
			}
		}

		Array &operator=(const Array& other)
		{
			delete _array;
			_array = new T[other._size];
			_size = other._size;
			for (unsigned int i = 0; i < _size; i++)
			{
				_array[i] = other._array[i];
			}
			return (*this);
		}
		class	InvalidIndex : public std::exception {
			public:
				const char	*what() const throw(){
					return (INVALID_INDEX);
				}
		};
		T &operator[](unsigned int index)
		{
			if (index < 0 || index >= _size)
				throw InvalidIndex();
			return (_array[index]);
		}
		unsigned int size() const
		{
			return _size;
		}
	private:
		unsigned int _size;
		T *_array;
};

