/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:44:08 by joopark           #+#    #+#             */
/*   Updated: 2021/05/11 20:38:25 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string Name) : 
	ClapTrap(60, 60, 120, 120, 1, Name, 60, 5, 0) {
	std::cout << "\033[1;33m";
	std::cout << "[NINJA-TP - ";
	std::cout << Name;
	std::cout << " has joined the game]";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap& ninjatrap) : ClapTrap(ninjatrap) {
	if (this != &ninjatrap)
		*this = ninjatrap;
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap& ninjatrap) {
	if (this != &ninjatrap) {
		ClapTrap::operator=(ninjatrap);
	}
	return (*this);
}

NinjaTrap::~NinjaTrap() {
	std::cout << "\033[1;33m";
	std::cout << "[NINJA-TP - ";
	std::cout << _name;
	std::cout << " has left the game.]";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void NinjaTrap::rangedAttack(std::string const & target) {
	std::cout << "\033[1;95m";
	std::cout << "NINJA-TP ";
	std::cout << target;
	std::cout << " attacks ";
	std::cout << _name;
	std::cout << " at range, causing ";
	std::cout << _ranged_attack_damage;
	std::cout << " points of damage!";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void NinjaTrap::meleeAttack(std::string const & target) {
	std::cout << "\033[1;95m";
	std::cout << "NINJA-TP ";
	std::cout << target;
	std::cout << " attacks ";
	std::cout << _name;
	std::cout << " at melee, causing ";
	std::cout << _melee_attack_damage;
	std::cout << " points of damage!";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap& target) {
	std::cout << "\033[1;95m";
	std::cout << "NINJA-TP ";
	std::cout << target.getName();
	std::cout << " can't attack!";
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap& target) {
	std::cout << "\033[1;95m";
	std::cout << "NINJA-TP ";
	std::cout << this->getName();
	std::cout << " attacks ";
	std::cout << target.getName();
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap& target) {
	std::cout << "\033[1;95m";
	std::cout << "NINJA-TP ";
	std::cout << this->getName();
	std::cout << " attacks ";
	std::cout << target.getName();
	std::cout << "\033[0m";
	std::cout << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap& target) {
	std::cout << "\033[1;95m";
	std::cout << "NINJA-TP ";
	std::cout << this->getName();
	std::cout << " attacks ";
	std::cout << target.getName();
	std::cout << "\033[0m";
	std::cout << std::endl;
}
