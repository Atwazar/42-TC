/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:37:42 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/27 18:37:43 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <stack>
#include <list>
#include <iostream>
#include <deque>

#pragma once

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public :
		MutantStack() : MutantStack<T, Container>::stack(){};
		~MutantStack(){};
		MutantStack(const MutantStack& other) : MutantStack<T, Container>::stack(other){};
		MutantStack &operator=(const MutantStack& other){
			*this = MutantStack<T, Container>::stack::operator=(other);
			return (*this);
		};
		typedef typename Container::iterator iterator;
		typedef typename Container::iterator reverse_iterator;
		iterator begin(){
			return this->c.begin();
		}
		iterator end(){
			return this->c.end();
		}
		reverse_iterator rbegin(){
			return this->c.rbegin();
		}
		reverse_iterator rend(){
			return this->c.rend();
		}
};
