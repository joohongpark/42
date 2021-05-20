/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:54:56 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 20:00:59 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator() {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator & assaultterminator) {
	if (this != &assaultterminator)
		*this = assaultterminator;
}

AssaultTerminator & AssaultTerminator::operator=(const AssaultTerminator & assaultterminator) {
	if (this != &assaultterminator)
		this->ISpaceMarine::operator=(assaultterminator);
	return (*this);
}

AssaultTerminator::~AssaultTerminator(void) {
	std::cout << "I'll be back..." << std::endl;
}

ISpaceMarine* AssaultTerminator::clone(void) const {
	return (new AssaultTerminator(*this));
}

void AssaultTerminator::battleCry(void) const {
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack(void) const {
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack(void) const {
	std::cout << "* attacks with chainfists *" << std::endl;
}
