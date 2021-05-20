/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:31:43 by joopark           #+#    #+#             */
/*   Updated: 2021/05/18 15:41:22 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type) {}

Enemy::Enemy(const Enemy & enemy) {
	if (this != &enemy)
		*this = enemy;
}

Enemy & Enemy::operator=(const Enemy & enemy) {
	if (this != &enemy) {
		this->_hp = enemy._hp;
		this->_type = enemy._type;
	}
	return (*this);
}

Enemy::~Enemy() {}

std::string Enemy::getType(void) const {
	return (_type);
}

int Enemy::getHP(void) const {
	return (_hp);
}

void Enemy::takeDamage(int damage) {
	if (damage >= 0) {
		if (_hp < damage)
			_hp = 0;
		else
			_hp -= damage;
	}
}
