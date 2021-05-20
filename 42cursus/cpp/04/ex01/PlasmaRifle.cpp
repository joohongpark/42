/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:49:38 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 19:50:05 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Palsma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(const PlasmaRifle & plasmarifle) : AWeapon(plasmarifle) {
	if (this != &plasmarifle)
		*this = plasmarifle;
}

PlasmaRifle & PlasmaRifle::operator=(const PlasmaRifle & plasmarifle) {
	if (this != &plasmarifle)
		this->AWeapon::operator=(plasmarifle);
	return (*this);
}

PlasmaRifle::~PlasmaRifle() {}

void PlasmaRifle::attack(void) const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
