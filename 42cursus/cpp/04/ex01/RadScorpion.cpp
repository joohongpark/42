/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:09:54 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 19:51:35 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion & radscorpion) : Enemy(radscorpion) {
	if (this != &radscorpion)
		*this = radscorpion;
}

RadScorpion & RadScorpion::operator=(const RadScorpion & radscorpion) {
	if (this != &radscorpion)
		this->Enemy::operator=(radscorpion);
	return (*this);
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *" << std::endl;
}

void RadScorpion::takeDamage(int damage) {
	Enemy::takeDamage(damage - 3);
}
