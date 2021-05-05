/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:28:25 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 00:22:46 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void) {
	Zombie zombie_on_stack("puju", "on stack");
	Zombie *zombie_on_heap = new Zombie("pupuju", "on heap");
	Zombie *zombie_on_heap_by_zombieevent;
	ZombieEvent zombieevent;

	zombie_on_stack.announce();

	zombie_on_heap->announce();
	delete zombie_on_heap;

	zombieevent.setZombieType("by ZombieEvent");
	zombie_on_heap_by_zombieevent = zombieevent.newZombie("jupu");
	zombie_on_heap_by_zombieevent->announce();
	delete zombie_on_heap_by_zombieevent;
	zombie_on_heap_by_zombieevent = NULL;

	zombieevent.setZombieType("by ZombieEvent_rand");
	zombie_on_heap_by_zombieevent = zombieevent.randomChump();
	zombie_on_heap_by_zombieevent->announce();
	delete zombie_on_heap_by_zombieevent;
	zombie_on_heap_by_zombieevent = NULL;

	return (0);
}
