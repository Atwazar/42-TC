/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:07:56 by thelaine          #+#    #+#             */
/*   Updated: 2024/10/04 13:07:57 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static unsigned long long	init_time()
{
	struct timeval	starting_time_struct;

	unsigned long long starting_time = 0;
	gettimeofday(&starting_time_struct, 0);
	starting_time += starting_time_struct.tv_sec * 1000000;
	starting_time += starting_time_struct.tv_usec;
	return (starting_time);
}

static unsigned long long	get_elapsed_time(long starting_time)
{
	struct timeval	actual_time;
	unsigned long long			time;

	gettimeofday(&actual_time, 0);
	time = actual_time.tv_sec * 1000000;
	time += actual_time.tv_usec;
	time -= starting_time;
	return (time);
}

template <typename T>
static void print_container(T& container)
{
	int j = 0;
	typename T::iterator it;
	for(it = container.begin(); it != container.end() && j < NUMBER_OF_NUMBERS_DISPLAYED; it++)
	{
		std::cout << *it << " ";
		j++;
	}
	if (it != container.end())
		std::cout << "[...]";
	std::cout << std::endl;
}

template <typename T>
static bool is_in_container(T& container, int to_find, std::string container_type)
{
	typename T::iterator i = std::find(container.begin(), container.end(), to_find);
	if (i == container.end())
		return (false);
	if (container_type == DISPLAYING_MESSAGE)
		std::cout << "Error: there is at least two \'" << *i << "\' in the args given" << std::endl;
	return (true);
}

template <typename T>
void sort_pairs(T& A, T& B)
{
	typename T::iterator it_A = A.begin();
	typename T::iterator it_B = B.begin();
	typename T::iterator end_A = A.end();
	while(it_A != end_A)
	{
		if (*it_A < *it_B)
			std::swap(*it_A, *it_B);
		it_A++;
		it_B++;
	}
}

template <typename T>
typename T::iterator select_iterator(T& container, int index)
{
	typename T::iterator it = container.begin();
	for (int i = 0; i < index; i++)
		it++;
	return it;
}

template <typename T>
void merge(T& A, T& B, int start, int end, int middle)
{
	T new_A;
	T new_B;

	typename T::iterator it_A = A.begin();
	typename T::iterator it_B = B.begin();
	typename T::iterator start_A = select_iterator(A, start);


	typename T::iterator middle_A = select_iterator(A, middle);

	typename T::iterator middle_A_clone = middle_A;
	typename T::iterator middle_B = select_iterator(B, middle);


	typename T::iterator end_A = select_iterator(A, end);

	typename T::iterator end_B = select_iterator(B, end);


	while (it_A != start_A)
	{
		new_A.push_back(*it_A);
		new_B.push_back(*it_B);
		it_A++;
		it_B++;
	}

	while (it_A != middle_A_clone && middle_A != end_A)
	{
		if (*it_A < *middle_A)
		{
			new_A.push_back(*it_A);
			new_B.push_back(*it_B);
			it_A++;
			it_B++;
		}
		else
		{
			new_A.push_back(*middle_A);
			new_B.push_back(*middle_B);
			middle_A++;
			middle_B++;
		}
	}
	while (it_A != middle_A_clone)
	{
		new_A.push_back(*it_A);
		new_B.push_back(*it_B);
		it_A++;
		it_B++;
	}
	while (middle_A != end_A)
	{
		new_A.push_back(*middle_A);
		new_B.push_back(*middle_B);
		middle_A++;
		middle_B++;
	}
	while (end_A != A.end())
	{
		new_A.push_back(*end_A);
		new_B.push_back(*end_B);
		end_A++;
		end_B++;
	}
	A = new_A;
	B = new_B;
}

///////////////////////////TEMPLATE MERGE SORT ///////////////////////////////////////

template <typename T>
void merge_sort(T& A, T& B, int start, int end)
{
	if (end - start > 1)
	{
		int middle = start + ((end - start)/ 2);
		if (middle == start)
			middle++;
		merge_sort(A, B, start, middle);
		merge_sort(A, B, middle, end);
		merge(A, B, start, end, middle);
	}
}


///////////////////////////TEMPLATE INSERTION SORT USING BINARY OPTIMIZATION///////////////////////////////////////

template <typename T>
void insertion_sort(T& A, T& B, int *weird_array)
{
	typename T::iterator it = B.begin();
	typename T::iterator end = B.end();
	typename T::iterator moving = A.begin();
	int i = 0;
	if (it != end)
	{
		A.insert(moving, *it);
		it++;
	}
	if (it != end)
	{
		moving = A.begin();
		while (i < 3)
		{
			if (*it < *moving)
			{
				A.insert(moving, *it);
				break;
			}
			moving++;
			i++;
		}
		if (i == 3)
			A.insert(moving, *it);
		it++;
	}

	if (weird_array)
	{
		i = 0;
		int j;
		while (weird_array[i] != 0)
		{
			j = 0;
			moving = A.begin();
			it = select_iterator(B, weird_array[i] - 1);
			while (j < weird_array[i] + i + 2)
			{
				if (*it < *moving && *it)
				{
					A.insert(moving, *it);
					break;
				}
				moving++;
				j++;
			}
			i++;
		}
	}
}

///////////////////////////TEMPLATE GLOBAL ALGORYTHM///////////////////////////////////////

template <typename T>
void merge_insert(T& container, int *number_array, int ac, int *weird_array, std::string container_type)
{
	unsigned long long starting_time = init_time();
	for (int i = 0; i < ac - 1; i++)
	{
		if (is_in_container(container, number_array[i], container_type) == true){
			return;}
		container.push_back(number_array[i]);
	}
	if (container.size() % 2 == 1)
		container.push_back(BAD_NUMBER);
	T A;
	T B;
	for(typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		A.push_back(*it++);
		B.push_back(*it);
	}

	sort_pairs(A, B);
	merge_sort(A, B, 0, A.size());

	insertion_sort(A, B, weird_array);

	if (*A.begin() == BAD_NUMBER)
		A.erase(A.begin());

	unsigned long long elapsed_time = get_elapsed_time(starting_time);
	if (container_type == DISPLAYING_MESSAGE)
	{
		std::cout << "before:	";
		int j;
		for (j = 0; j < ac - 1 && j < NUMBER_OF_NUMBERS_DISPLAYED; j++)
			std::cout << number_array[j] << " ";
		if (j < ac -1)
			std::cout << "[...]";
		std::cout << std::endl;
		std::cout << "after:	";
		print_container(A);
	}
	std::cout << "Time to process a range of " << A.size() << " elements with " << container_type
	<< ": " << elapsed_time << " us." << std::endl;
}
///////////////////////////USING VECTORS///////////////////////////////////////
void merge_insert_vect(int *number_array, int ac, int *weird_array)
{
	std::vector<int> vector;
	merge_insert(vector, number_array, ac, weird_array, "std::vector");
}

void merge_insert_list(int *number_array, int ac, int *weird_array)
{

	std::list<int> list;
	merge_insert(list, number_array, ac, weird_array, "std::list");
}
