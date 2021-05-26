/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:20:46 by joopark           #+#    #+#             */
/*   Updated: 2021/05/25 00:51:54 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Print.hpp"

Print::Print() {}

Print::Print(const Print & print) {
	if (this != &print)
		*this = print;
}

Print & Print::operator=(const Print & print) {
	(void) print;
	return (*this);
}

Print::~Print() {}

void Print::printNumber(bool possible, char c) {
	std::cout << "char: ";
	if (possible == false) {
		std::cout << "impossible";
	} else {
		if (isprint(c) == false) {
			std::cout << "Non displayable";
		} else {
			std::cout << "'" << c << "'";
		}
	}
	std::cout << std::endl;
}

void Print::printNumber(bool possible, int i) {
	std::cout << "int: ";
	std::cout.setf(std::ios::fixed);
	std::cout.precision(1);
	if (possible == false) {
		std::cout << "impossible";
	} else {
		std::cout << i;
	}
	std::cout << std::endl;
}

void Print::printNumber(bool possible, float f) {
	std::cout << "float: ";
	std::cout.setf(std::ios::fixed);
	std::cout.precision(1);
	if (possible == false) {
		std::cout << "impossible";
	} else {
		std::cout << f << "f";
	}
	std::cout << std::endl;
}

void Print::printNumber(bool possible, double d) {
	std::cout << "double: ";
	if (possible == false) {
		std::cout << "impossible";
	} else {
		std::cout << d;
	}
	std::cout << std::endl;
}

