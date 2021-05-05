/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:10:00 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 01:02:10 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : weapon_(weapon), name_(name) {}

void HumanA::attack() {
	std::cout << name_;
	std::cout << " attacks with his ";
	std::cout << weapon_.getType();
	std::cout << std::endl;
}
