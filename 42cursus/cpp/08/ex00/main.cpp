/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:00:13 by joopark           #+#    #+#             */
/*   Updated: 2021/05/29 20:10:10 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

void vector_test(void) {
	std::vector<int>::iterator iter;
	std::vector<int> data;

	for (int i = 0; i < 11; i++)
		data.push_back(i);
	try {
		iter = easyfind(data, 0);
		std::cout << *iter << std::endl;
		iter = easyfind(data, 10);
		std::cout << *iter << std::endl;
		iter = easyfind(data, 13);
		std::cout << *iter << std::endl;
	} catch(const char * e) {
		std::cout << e << '\n';
	}
}

void deque_test(void) {
	std::deque<int>::iterator iter;
	std::deque<int> data;

	for (int i = 0; i < 11; i++)
		data.push_back(i);
	try {
		iter = easyfind(data, 0);
		std::cout << *iter << std::endl;
		iter = easyfind(data, 10);
		std::cout << *iter << std::endl;
		iter = easyfind(data, 13);
		std::cout << *iter << std::endl;
	} catch(const char * e) {
		std::cout << e << '\n';
	}
}

void list_test(void) {
	std::list<int>::iterator iter;
	std::list<int> data;

	for (int i = 0; i < 11; i++)
		data.push_back(i);
	try {
		iter = easyfind(data, 0);
		std::cout << *iter << std::endl;
		iter = easyfind(data, 10);
		std::cout << *iter << std::endl;
		iter = easyfind(data, 13);
		std::cout << *iter << std::endl;
	} catch(const char * e) {
		std::cout << e << '\n';
	}
}

int main (void) {
	vector_test();
	deque_test();
	list_test();
	return (0);
}