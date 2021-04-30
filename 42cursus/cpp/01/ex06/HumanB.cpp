/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:10:00 by joopark           #+#    #+#             */
/*   Updated: 2021/04/30 00:10:09 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : name_(), weapon_() {}

HumanB::HumanB(std::string name) : name_(name), weapon_() {}

HumanB::HumanB(std::string name, Weapon weapon) : name_(name), weapon_(weapon) {}

void HumanB::attack() {
	std::cout << name_;
	std::cout << " attacks with his ";
	std::cout << weapon_.getType();
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon weapon) {
	weapon_ = weapon;
}
