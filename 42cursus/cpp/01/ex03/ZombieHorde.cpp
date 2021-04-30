/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 21:39:39 by joopark           #+#    #+#             */
/*   Updated: 2021/04/28 22:53:11 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde() {
	zombies = NULL;
}

ZombieHorde::ZombieHorde(int n) {
	char tmp[10];

	if (n > 0) {
		zombies = new Zombie[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				tmp[j] = char(rand() % ('Z' - 'A') + 'A');
			}
			zombies[i].setName(std::string(tmp, 10));
			zombies[i].announce();
		}
	} else {
		zombies = NULL;
	}
}

ZombieHorde::~ZombieHorde() {
	delete [] zombies;
}

