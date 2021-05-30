/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 20:02:12 by joopark           #+#    #+#             */
/*   Updated: 2021/05/30 01:34:02 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"

void subject(void) {
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void custom1(void) {
	try {
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(12);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void custom2(void) {
	try {
		Span sp = Span(5);
		sp.addNumber(5);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void custom3(void) {
	try {
		std::vector<int> tmp;
		for (int i = 0; i < 12345; i++)
			tmp.push_back(i - 10000);
		Span sp = Span(12345);
		sp.addNumber(tmp.begin(), tmp.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	std::cout << "==================in subject==================" << std::endl;
	subject();
	std::cout << "==================custom 1==================" << std::endl;
	custom1();
	std::cout << "==================custom 2==================" << std::endl;
	custom2();
	std::cout << "==================custom 3==================" << std::endl;
	custom3();
	return (0);
}