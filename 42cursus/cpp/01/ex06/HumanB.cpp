/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:10:00 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 01:07:24 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : weapon_(), name_() {}

HumanB::HumanB(std::string name) : weapon_(), name_(name) {}

HumanB::HumanB(std::string name, Weapon& weapon) : weapon_(&weapon), name_(name) {}

void HumanB::attack() {
	std::cout << name_;
	std::cout << " attacks with his ";
	std::cout << weapon_->getType();
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	weapon_ = &weapon;
}
