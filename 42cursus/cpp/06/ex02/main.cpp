/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:24:01 by joopark           #+#    #+#             */
/*   Updated: 2021/05/25 13:35:36 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>

Base * generate(void) {
	int r;
	static int seed = 0;

	seed += time(NULL);
	srand(seed);
	r = rand() % 3;
	if (r == 0)
		return (new A());
	else if (r == 1)
		return (new B());
	else
		return (new C());
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
	if (dynamic_cast<A *>(&p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p) != NULL)
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

int main (void) {
	Base * b1;
	Base * b2;

	b1 = generate();
	b2 = generate();

	identify_from_pointer(b1);
	identify_from_reference(*b2);
	return (0);
}