/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:04:17 by joopark           #+#    #+#             */
/*   Updated: 2021/05/15 09:32:14 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << name;
	std::cout << ", ";
	std::cout << title;
	std::cout << ", is born!";
	std::cout << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer& sorcerer) {
	if (this != &sorcerer)
		*this = sorcerer;
}

Sorcerer& Sorcerer::operator=(const Sorcerer& sorcerer) {
	if (this != &sorcerer) {
		this->_name = sorcerer._name;
		this->_title = sorcerer._title;
	}
	return (*this);
}

Sorcerer::~Sorcerer() {
	std::cout << _name;
	std::cout << ", ";
	std::cout << _title;
	std::cout << ", is dead. Consequences will never be the same!";
	std::cout << std::endl;
}

std::string Sorcerer::getName(void) const {return (_name);}

std::string Sorcerer::getTitle(void) const {return (_title);}

void Sorcerer::polymorph(Victim const& victim) const {
	victim.getPolymorphed();
}

void Sorcerer::polymorph(Peon const& peon) const {
	peon.getPolymorphed();
}

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcerer) {
	out << "I am ";
	out << sorcerer.getName();
	out << ", ";
	out << sorcerer.getTitle();
	out << ", and I like ponies!";
	out << std::endl;
    return (out);
}


