/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:08:30 by joopark           #+#    #+#             */
/*   Updated: 2021/04/28 00:33:21 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name, int age, std::string color, std::string status) {
	Name = name;
	Age = age;
	Color = color;
	Status = status;
}

void Pony::greeting(void) {
	std::cout << "hello! i'm " << Name << ", and i'm " << Age << ".";
	std::cout << "and my color is " << Color << "." << std::endl;
}

void Pony::status(void) {
	std::cout << "I'm " << Status << "." << std::endl;
}

void Pony::changeStatus(std::string status) {
	Status = status;
}
