/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:18:16 by joopark           #+#    #+#             */
/*   Updated: 2021/05/11 17:10:15 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : 
	ClapTrap(100, 100, 50, 50, 1, Name, 20, 15, 3) {
	std::cout << "\033[1;33m";
	std::cout << "[SC4V-TP - ";
	std::cout << Name;
	std::cout << " has joined the game]";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& fragtrap) : ClapTrap(fragtrap) {
	if (this != &fragtrap)
		*this = fragtrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& fragtrap) {
	if (this != &fragtrap) {
		ClapTrap::operator=(fragtrap);
		this->_rand_seed = fragtrap._rand_seed;
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
