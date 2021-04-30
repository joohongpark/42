/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:28:25 by joopark           #+#    #+#             */
/*   Updated: 2021/04/28 21:21:42 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void) {
	Zombie zombie_stack("puju", "on stack");
	Zombie *zombie_heap = new Zombie("pupuju", "on heap");
	Zombie *zombie_by_ze;
	ZombieEvent zombieevent;

	zombie_stack.announce();
	zombie_heap->announce();
	delete zombie_heap;

	zombieevent.setZombieType("by ZombieEvent");
	zombie_by_ze = zombieevent.newZombie("jupu");
	zombie_by_ze->announce();
	delete zombie_by_ze;

	zombieevent.setZombieType("by ZombieEvent_rand");
	zombie_by_ze = zombieevent.randomChump();
	zombie_by_ze->announce();
	delete zombie_by_ze;

	return (0);
}