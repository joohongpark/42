/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:46:52 by joopark           #+#    #+#             */
/*   Updated: 2021/05/19 15:09:28 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type), _xp(0) {}

AMateria::AMateria(const AMateria & amateria) {
	if (this != &amateria)
		*this = amateria;
}

AMateria & AMateria::operator=(const AMateria & amateria) {
	if (this != &amateria) {
		this->_type = amateria._type;
		this->_xp = amateria._xp;
	}
	return (*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType(void) const {
	return (_type);
}

unsigned int AMateria::getXP(void) const {
	return (_xp);
}

void AMateria::use(ICharacter& target) {
	(void) target;
	//std::cout << "* shoots an ice bolt at NAME *" << std::endl;
	_type += 10;
}
