/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:49:38 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 19:50:45 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(const PowerFist & powerfist) : AWeapon(powerfist) {
	if (this != &powerfist)
		*this = powerfist;
}

PowerFist & PowerFist::operator=(const PowerFist & powerfist) {
	if (this != &powerfist)
		this->AWeapon::operator=(powerfist);
	return (*this);
}

PowerFist::~PowerFist() {}

void PowerFist::attack(void) const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
