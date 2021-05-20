/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:04:22 by joopark           #+#    #+#             */
/*   Updated: 2021/05/15 09:26:38 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string name) : _name(name) {
	std::cout << "Some random victim called ";
	std::cout << _name;
	std::cout << " just appeared!";
	std::cout << std::endl;
}

Victim::Victim(const Victim& victim) {
	if (this != &victim)
		*this = victim;
}

Victim& Victim::operator=(const Victim& victim) {
	if (this != &victim) {
		this->_name = victim._name;
	}
	return (*this);
}

std::string Victim::getName(void) const {return (_name);}

Victim::~Victim() {
	std::cout << "Victim ";
	std::cout << _name;
	std::cout << " just died for no apparent reason!";
	std::cout << std::endl;
}

void Victim::getPolymorphed(void) const {
	std::cout << this->getName();
	std::cout << " has been turned into a cute little sheep!";
	std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Victim &victim) {
	out << "I am ";
	out << victim.getName();
	out << " and I like otters!";
	out << std::endl;
    return (out);
}
