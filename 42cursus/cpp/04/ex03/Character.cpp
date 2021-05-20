/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:23:25 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 17:07:42 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_m[i] = NULL;
}

Character::Character(const Character & character) {
	if (this != &character)
		*this = character;
}

Character & Character::operator=(const Character & character) {
	if (this != &character) {
		for (int i = 0; i < 4; i++)
			this->_m[i] = character._m[i];
	}
	return (*this);
}

Character::~Character() {}

std::string const & Character::getName(void) const {
	 return (_name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_m[i] == NULL) {
			_m[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4)
		_m[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4) {
		if (_m[idx] != NULL)
			_m[idx]->use(target);
	}
}
