/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:18:16 by joopark           #+#    #+#             */
/*   Updated: 2021/05/11 17:10:42 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : 
	_hit_points(100),
	_max_hit_points(100),
	_energy_points(50),
	_max_energy_points(50),
	_level(1),
	_name(Name),
	_melee_attack_damage(20),
	_ranged_attack_damage(15),
	_armor_damage_reduction(3) {
	std::cout << "\033[1;33m";
	std::cout << "[SC4V-TP - ";
	std::cout << Name;
	std::cout << " has joined the game]";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& fragtrap) {
	if (this != &fragtrap)
		*this = fragtrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& fragtrap) {
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

ScavTrap::~ScavTrap() {
	std::cout << "\033[1;33m";
	std::cout << "[SC4V-TP - ";
	std::cout << _name;
	std::cout << " has left the game.]";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void ScavTrap::rangedAttack(std::string const & target) {
	std::cout << "\033[1;95m";
	std::cout << "SC4V-TP ";
	std::cout << target;
	std::cout << " attacks ";
	std::cout << _name;
	std::cout << " at range, causing ";
	std::cout << _ranged_attack_damage;
	std::cout << " points of damage!";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "\033[1;95m";
	std::cout << "SC4V-TP ";
	std::cout << target;
	std::cout << " attacks ";
	std::cout << _name;
	std::cout << " at melee, causing ";
	std::cout << _melee_attack_damage;
	std::cout << " points of damage!";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
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

void ScavTrap::beRepaired(unsigned int amount) {
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

void ScavTrap::challengeNewcomer(std::string const & target) {
	int random;
	const static std::string challenges[5] = {
		"webserv",
		"ft_containers",
		"Exam Rank 04",
		"Exam Rank 05",
		"ft_transcendence"
	};

	std::cout << "\033[1;92m";
	std::cout << "[challenge] ";
	std::cout << "\033[0m";
	_rand_seed += time(NULL);
	if (_energy_points > 25) {
		srand(_rand_seed);
		random = rand() % 5;
		_energy_points -= 25;
		std::cout << "\033[1;92m";
		std::cout << target;
		std::cout << "'s challenge is ";
		std::cout << challenges[random];
		std::cout << "\033[0m";
		std::cout << std::endl;
	} else {
		std::cout << "\033[1;91m";
		std::cout << "not enough energy";
		std::cout << "\033[0m";
		std::cout << std::endl;
	}
}
