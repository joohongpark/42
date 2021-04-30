/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:28:37 by joopark           #+#    #+#             */
/*   Updated: 2021/04/28 21:19:42 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_H
#define ZOMBIEEVENT_H

#include "Zombie.hpp"
#include <ctime>

class ZombieEvent {
	private:
		std::string Type;
	public:
		ZombieEvent(/* args */);
		ZombieEvent(std::string type);
		Zombie *newZombie(std::string name);
		void setZombieType(std::string type);
		Zombie *randomChump(void);
};

#endif