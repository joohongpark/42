/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:28:30 by joopark           #+#    #+#             */
/*   Updated: 2021/04/28 22:52:38 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : Name(), Type() {
}

Zombie::Zombie(std::string name, std::string type) : Name(name), Type(type) {
}

void Zombie::announce(void) {
	std::cout << '<' << Name << " (" << Type << ")> Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::setName(std::string name) {
	Name = name;
}