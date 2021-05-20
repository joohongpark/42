/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:09:54 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 19:51:44 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant & supermutant) : Enemy(supermutant) {
	if (this != &supermutant)
		*this = supermutant;
}

SuperMutant & SuperMutant::operator=(const SuperMutant & supermutant) {
	if (this != &supermutant)
		this->Enemy::operator=(supermutant);
	return (*this);
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh..." << std::endl;
}
