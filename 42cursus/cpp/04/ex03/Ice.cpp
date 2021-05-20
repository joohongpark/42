/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:52:43 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 15:30:14 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice & ice) : AMateria(ice) {
	if (this != &ice)
		*this = ice;
}

Ice & Ice::operator=(const Ice & ice) {
	if (this != &ice)
		this->AMateria::operator=(ice);
	return (*this);
}

Ice::~Ice() {}

AMateria* Ice::clone(void) const {
	return (new Ice());
}

void Ice::use(ICharacter& target) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName();
	std::cout << " *" << std::endl;
}
