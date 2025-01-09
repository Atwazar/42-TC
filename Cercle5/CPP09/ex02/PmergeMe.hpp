/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:08:00 by thelaine          #+#    #+#             */
/*   Updated: 2024/10/04 13:08:01 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BAD_NUMBER -1
#define DISPLAYING_MESSAGE "std::vector"
// #define DISPLAYING_MESSAGE "std::list"
#define NUMBER_OF_NUMBERS_DISPLAYED 4

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>
#include <limits.h>
#include <cstdlib>
#include <sys/time.h>
#include <algorithm>
#include <math.h>

void merge_insert_vect(int *number_array, int ac, int *weird_array);
void merge_insert_list(int *number_array, int ac, int *weird_array);


