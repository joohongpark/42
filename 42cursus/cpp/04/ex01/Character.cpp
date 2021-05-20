/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:35:07 by joopark           #+#    #+#             */
/*   Updated: 2021/05/18 19:38:29 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _ap(40), _name(name), _aweapon(NULL) {}

Character::Character(const Character & character) {
	if (this != &character)
		*this = character;
}

Character & Character::operator=(const Character & character) {
	if (this != &character) {
		this->_ap = character._ap;
		this->_name = character._name;
	}
	return (*this);
}

Character::~Character() {}

void Character::equip(AWeapon* aweapon) {
	_aweapon = aweapon;
}

void Character::attack(Enemy* enemy) {
	if (_aweapon != NULL && (_ap - _aweapon->getAPCost()) >= 0) {
		std::cout << _name;
		std::cout << " attacks ";
		std::cout << enemy->getType();
		std::cout << " with a ";
		std::cout << _aweapon->getName();
		std::cout << std::endl;
		enemy->takeDamage(_aweapon->getDamage());
		_aweapon->attack();
		_ap -= _aweapon->getAPCost();
		if (enemy->getHP() == 0)
			delete enemy;
	}
}

std::string Character::getName(void) const {
	return (_name);
}

int Character::getAP(void) const {
	return (_ap);
}

bool Character::isEquip(void) const {
	return (_aweapon != NULL);
}

std::string Character::getWeaponName(void) const {
	if (_aweapon == NULL) {
		return ("");
	} else {
		return (_aweapon->getName());
	}
}


std::ostream &operator<<(std::ostream &out, const Character & character) {
	out << character.getName();
	out << " has ";
	out << character.getAP();
	std::cout << " AP and ";
	if (!character.isEquip()) {
		std::cout << "is unarmed";
	} else {
		std::cout << "wields a ";
		std::cout << character.getWeaponName();
	}
	out << std::endl;
    return (out);
}
