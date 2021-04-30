/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:28:35 by joopark           #+#    #+#             */
/*   Updated: 2021/04/28 21:19:57 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() : Type() {
}

ZombieEvent::ZombieEvent(std::string type) : Type(type) {
}

Zombie *ZombieEvent::newZombie(std::string name) {
	return (new Zombie(name, Type));
}

void ZombieEvent::setZombieType(std::string type) {
	Type = type;
}

Zombie *ZombieEvent::randomChump(void) {
	Zombie *zombie;
	char tmp[10];
	
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		tmp[i] = char(rand() % ('Z' - 'A') + 'A');
	}
	zombie = new Zombie(std::string(tmp, 10), Type);
	zombie->announce();
	return (zombie);
}
