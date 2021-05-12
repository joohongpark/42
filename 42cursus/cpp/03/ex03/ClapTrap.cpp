/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:51:07 by joopark           #+#    #+#             */
/*   Updated: 2021/05/11 19:43:56 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(	unsigned int hit_points,
					unsigned int max_hit_points,
					unsigned int energy_points,
					unsigned int max_energy_points,
					unsigned int level,
					std::string name,
					unsigned int melee_attack_damage,
					unsigned int ranged_attack_damage,
					unsigned int armor_damage_reduction	) : 
	_hit_points(hit_points),
	_max_hit_points(max_hit_points),
	_energy_points(energy_points),
	_max_energy_points(max_energy_points),
	_level(level),
	_name(name),
	_melee_attack_damage(melee_attack_damage),
	_ranged_attack_damage(ranged_attack_damage),
	_armor_damage_reduction(armor_damage_reduction) {
	std::cout << "\033[1;33m";
	std::cout << "[CL4P-TP - ";
	std::cout << name;
	std::cout << " has joined the game]";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& fragtrap) {
	if (this != &fragtrap)
		*this = fragtrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& fragtrap) {
	if (this != &fragtrap) {
		this->_hit_points = fragtrap._hit_points;
		this->_max_hit_points = fragtrap._max_hit_points;
		this->_energy_points = fragtrap._energy_points;
		this->_max_energy_points = fragtrap._max_energy_points;
		this->_level = fragtrap._level;
		this->_name = fragtrap._name;
		this->_melee_attack_damage = fragtrap._melee_attack_damage;
		this->_ranged_attack_damage = fragtrap._ranged_attack_damage;
		this->_armor_damage_reduction = fragtrap._armor_damage_reduction;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "\033[1;33m";
	std::cout << "[CL4P-TP - ";
	std::cout << _name;
	std::cout << " has left the game.]";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	unsigned int damage;

	damage = amount * unsigned(_armor_damage_reduction / _level);
	if (_hit_points >= damage)
		_hit_points -= damage;
	else
		_hit_points = 0;
	std::cout << "\033[1;91m";
	std::cout << _name;
	std::cout << " is under attack! (HP : ";
	std::cout << _hit_points;
	std::cout << " / ";
	std::cout << _max_hit_points;
	std::cout << ")";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	int repair;

	repair = amount * int(_armor_damage_reduction / _level);
	if ((_hit_points + repair) <= _max_hit_points)
		_hit_points += repair;
	else
		_hit_points = _max_hit_points;
	std::cout << "\033[1;92m";
	std::cout << _name;
	std::cout << " is repaired! (HP : ";
	std::cout << _hit_points;
	std::cout << " / ";
	std::cout << _max_hit_points;
	std::cout << ")";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

std::string ClapTrap::getName(void) {
	return (_name);
}
