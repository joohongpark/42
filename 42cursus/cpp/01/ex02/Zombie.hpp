/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:28:32 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 00:22:41 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
	private:
		std::string Name;
		std::string Type;
	public:
		Zombie();
		Zombie(std::string name, std::string type);
		void announce(void);
};

#endif
