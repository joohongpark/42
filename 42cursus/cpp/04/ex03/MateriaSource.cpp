/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:30:35 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 20:42:45 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_m[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource & materiasource) {
	if (this != &materiasource)
		*this = materiasource;
}

MateriaSource & MateriaSource::operator=(const MateriaSource & materiasource) {
	if (this != &materiasource) {
		for (int i = 0; i < 4; i++)
			this->_m[i] = materiasource._m[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource() {}

void MateriaSource::learnMateria(AMateria* amateria) {
	for (int i = 0; i < 4; i++) {
		if (_m[i] == NULL) {
			_m[i] = amateria;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_m[i] != NULL) {
			if (_m[i]->getType() == type)
				return (_m[i]);
		}
	}
	return (NULL);
}
