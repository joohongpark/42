/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:24:01 by joopark           #+#    #+#             */
/*   Updated: 2021/05/28 18:52:07 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>

Base * generate(void) {
	int r;

	r = rand() % 3;
	if (r == 0) {
		std::cout << "generate - A" << std::endl;
		return (new A());
	} else if (r == 1) {
		std::cout << "generate - B" << std::endl;
		return (new B());
	} else {
		std::cout << "generate - C" << std::endl;
		return (new C());
	}
}

void identify_from_pointer(Base * p) {
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base & p) {
	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch(const std::exception& e) {
		try {
			B b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		} catch(const std::exception& e) {
			try {
				C c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			} catch(const std::exception& e) {
				std::cout << e.what() << '\n';
			}
		}
	}
}

int main (void) {
	Base * b1;
	Base * b2;
	srand(time(NULL));

	b1 = generate();
	b2 = generate();

	identify_from_pointer(b1);
	identify_from_reference(*b2);

	delete b1;
	delete b2;
	return (0);
}