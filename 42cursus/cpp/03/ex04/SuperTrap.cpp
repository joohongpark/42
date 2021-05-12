/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:18:42 by joopark           #+#    #+#             */
/*   Updated: 2021/05/11 23:30:06 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string Name) : 
	ClapTrap(100, 100, 50, 50, 1, Name, 20, 15, 3), FragTrap(Name), NinjaTrap(Name) {
	std::cout << "\033[1;33m";
	std::cout << "[SUPER-TP - ";
	std::cout << Name;
	std::cout << " has joined the game]";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap& supertrap) : ClapTrap(supertrap), FragTrap(supertrap), NinjaTrap(supertrap) {
	if (this != &supertrap)
		*this = supertrap;
}

SuperTrap& SuperTrap::operator=(const SuperTrap& supertrap) {
	if (this != &supertrap) {
		ClapTrap::operator=(supertrap);
		FragTrap::operator=(supertrap);
		NinjaTrap::operator=(supertrap);
	}
	return (*this);
}

SuperTrap::~SuperTrap() {
	std::cout << "\033[1;33m";
	std::cout << "[SUPER-TP - ";
	std::cout << _name;
	std::cout << " has left the game.]";
	std::cout << "\033[0m";
	std::cout << std::endl;
}
