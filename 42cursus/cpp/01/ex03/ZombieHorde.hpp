/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 21:39:42 by joopark           #+#    #+#             */
/*   Updated: 2021/04/28 22:40:18 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_H
#define ZOMBIEHORDE_H

#include "Zombie.hpp"
#include <ctime>

class ZombieHorde {
	private:
		Zombie *zombies;
	public:
		ZombieHorde();
		ZombieHorde(int n);
		~ZombieHorde();
};
#endif