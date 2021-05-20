/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:04:11 by joopark           #+#    #+#             */
/*   Updated: 2021/05/18 12:36:38 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon& peon) : Victim(peon) {
	if (this != &peon)
		*this = peon;
}

Peon& Peon::operator=(const Peon& peon) {
	if (this != &peon) {
		this->_name = peon._name;
	}
	return (*this);
}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed(void) const {
	std::cout << this->getName();
	std::cout << " has been turned into a pink pony";
	std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Peon &peon) {
	out << "I am ";
	out << peon.getName();
	out << " and I like otters!";
	out << std::endl;
    return (out);
}
