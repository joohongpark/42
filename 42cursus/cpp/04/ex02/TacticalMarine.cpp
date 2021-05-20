/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:54:56 by joopark           #+#    #+#             */
/*   Updated: 2021/05/19 02:26:22 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() {
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine & tacticalmarine) {
	if (this != &tacticalmarine)
		*this = tacticalmarine;
}

TacticalMarine & TacticalMarine::operator=(const TacticalMarine & tacticalmarine) {
	(void) tacticalmarine;
	return (*this);
}

TacticalMarine::~TacticalMarine(void) {
	std::cout << "Aaargh..." << std::endl;
}

ISpaceMarine* TacticalMarine::clone(void) const {
	return (new TacticalMarine(*this));
}

void TacticalMarine::battleCry(void) const {
	std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack(void) const {
	std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack(void) const {
	std::cout << "* attacks with a chainsword *" << std::endl;
}
