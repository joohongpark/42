/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:31:32 by joopark           #+#    #+#             */
/*   Updated: 2021/05/25 17:45:27 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void print_str(const char* str) {
	std::cout << str << std::endl;
}

void print_int(const int * str) {
	std::cout << *str << std::endl;
}

int main(void) {
	int intarrs[3] = {1, 2, 3};
	const char* strs[3] = {
		"text1",
		"text2",
		"text3"
	};
	const int* ints[3] = {&intarrs[0], &intarrs[1], &intarrs[2]};
	iter(strs, 3, print_str);
	iter(ints, 3, print_int);
	return (0);
}