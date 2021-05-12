/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:28:12 by joopark           #+#    #+#             */
/*   Updated: 2021/05/10 00:30:16 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name) : 
	_hit_points(100),
	_max_hit_points(100),
	_energy_points(100),
	_max_energy_points(100),
	_level(1),
	_name(Name),
	_melee_attack_damage(30),
	_ranged_attack_damage(20),
	_armor_damage_reduction(5) {
	std::cout << "\033[1;33m";
	std::cout << "[FR4G-TP ";
	std::cout << Name;
	std::cout << " has joined the game]";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragtrap) {
	if (this != &fragtrap)
		*this = fragtrap;
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap) {
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

FragTrap::~FragTrap() {
	std::cout << "\033[1;33m";
	std::cout << "[FR4G-TP ";
	std::cout << _name;
	std::cout << " has left the game.]";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void FragTrap::rangedAttack(std::string const & target) {
	std::cout << "\033[1;95m";
	std::cout << "FR4G-TP ";
	std::cout << target;
	std::cout << " attacks ";
	std::cout << _name;
	std::cout << " at range, causing ";
	std::cout << _ranged_attack_damage;
	std::cout << " points of damage!";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void FragTrap::meleeAttack(std::string const & target) {
	std::cout << "\033[1;95m";
	std::cout << "FR4G-TP ";
	std::cout << target;
	std::cout << " attacks ";
	std::cout << _name;
	std::cout << " at melee, causing ";
	std::cout << _melee_attack_damage;
	std::cout << " points of damage!";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
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

void FragTrap::beRepaired(unsigned int amount) {
	unsigned int repair;

	repair = amount * unsigned(_armor_damage_reduction / _level);
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

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	int random;

	_rand_seed += time(NULL);
	std::cout << "\033[1;92m";
	std::cout << "[random attack] ";
	std::cout << "\033[0m";
	if (_energy_points > 25) {
		srand(_rand_seed);
		random = rand() % 5;
		_energy_points -= 25;
		if (random == 0)
			rangedAttack(target);
		else if (random == 1)
			meleeAttack(target);
		else if (random == 2)
			AK47Attack(target);
		else if (random == 3)
			RPG7Attack(target);
		else
			ShotgunAttack(target);
	} else {
		std::cout << "\033[1;91m";
		std::cout << "not enough energy";
		std::cout << "\033[0m";
		std::cout << std::endl;
	}
}

void FragTrap::AK47Attack(std::string const & target) {
	std::cout << "\033[1;95m";
	std::cout << "FR4G-TP ";
	std::cout << target;
	std::cout << " attacks ";
	std::cout << _name;
	std::cout << " at AK-47, causing ";
	std::cout << _ranged_attack_damage;
	std::cout << " points of damage!";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void FragTrap::RPG7Attack(std::string const & target) {
	std::cout << "\033[1;95m";
	std::cout << "FR4G-TP ";
	std::cout << target;
	std::cout << " attacks ";
	std::cout << _name;
	std::cout << " at RPG-7, causing ";
	std::cout << _ranged_attack_damage;
	std::cout << " points of damage!";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void FragTrap::ShotgunAttack(std::string const & target) {
	std::cout << "\033[1;95m";
	std::cout << "FR4G-TP ";
	std::cout << target;
	std::cout << " attacks ";
	std::cout << _name;
	std::cout << " at Shotgun, causing ";
	std::cout << _ranged_attack_damage;
	std::cout << " points of damage!";
	std::cout << "\033[0m";
	std::cout << std::endl;
}
