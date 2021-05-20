/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:15:07 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 15:31:36 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure & cure) : AMateria(cure) {
	if (this != &cure)
		*this = cure;
}

Cure & Cure::operator=(const Cure & cure) {
	if (this != &cure)
		this->AMateria::operator=(cure);
	return (*this);
}

Cure::~Cure() {}

AMateria* Cure::clone(void) const {
	return (new Cure());
}

void Cure::use(ICharacter& target) {
	AMateria::use(target);
	std::cout << "* heals ";
	std::cout << target.getName();
	std::cout << "’s wounds *" << std::endl;
}
