/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:31:32 by joopark           #+#    #+#             */
/*   Updated: 2021/05/31 00:44:43 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T const & x) {
	std::cout << x << std::endl;
}

void print_str(const char * str) {
	std::cout << str << std::endl;
}

void print_string(std::string & str) {
	std::cout << str << std::endl;
}

void print_int_pointer(int * i) {
	std::cout << *i << std::endl;
}

void print_int(int i) {
	std::cout << i << std::endl;
}

int main(void) {
	int intarr[] = {0, 1, 2, 3, 4};
	int * intpointers[] = {&intarr[0], &intarr[1], &intarr[2], &intarr[3], &intarr[4]};
	const char* strs[] = {
		"text1",
		"text2",
		"text3"
	};
	std::string *strarr = new std::string[3];
	strarr[0] = strs[0];
	strarr[1] = strs[1];
	strarr[2] = strs[2];

	iter(intarr, 5, print_int);
	iter(intpointers, 5, print_int_pointer);
	iter(strs, 3, print_str);
	iter(strarr, 3, print_string);

	delete [] strarr;
	return (0);
}