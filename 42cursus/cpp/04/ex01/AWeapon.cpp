/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 09:44:34 by joopark           #+#    #+#             */
/*   Updated: 2021/05/18 12:49:10 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name), _apcost(apcost), _damage(damage) {}

AWeapon::AWeapon(const AWeapon & aweapon) {
	if (this != &aweapon)
		*this = aweapon;
}

AWeapon & AWeapon::operator=(const AWeapon & aweapon) {
	if (this != &aweapon) {
		this->_name = aweapon._name;
		this->_apcost = aweapon._apcost;
		this->_damage = aweapon._damage;
	}
	return (*this);
}

AWeapon::~AWeapon() {}

std::string AWeapon::getName(void) const {
	return (_name);
}

int AWeapon::getAPCost(void) const {
	return (_apcost);
}

int AWeapon::getDamage(void) const {
	return (_damage);
}