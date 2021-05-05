/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:10:00 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 00:57:30 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type() {}

Weapon::Weapon(std::string _type) : type(_type) {}

void Weapon::setType(std::string _type) {
	type = _type;
}

const std::string& Weapon::getType(void) {
	return (type);
}
