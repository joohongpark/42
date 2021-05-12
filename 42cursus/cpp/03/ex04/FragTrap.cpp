/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:28:12 by joopark           #+#    #+#             */
/*   Updated: 2021/05/11 16:56:32 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name) :
	ClapTrap(100, 100, 100, 100, 1, Name, 30, 20, 5) {
	std::cout << "\033[1;33m";
	std::cout << "[FR4G-TP ";
	std::cout << Name;
	std::cout << " has joined the game]";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragtrap) : ClapTrap(fragtrap) {
	if (this != &fragtrap)
		*this = fragtrap;
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap) {
	if (this != &fragtrap) {
		ClapTrap::operator=(fragtrap);
		this->_rand_seed = fragtrap._rand_seed;
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
