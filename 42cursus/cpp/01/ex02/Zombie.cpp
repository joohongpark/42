/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:28:30 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 00:13:53 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : Name(), Type() {}

Zombie::Zombie(std::string name, std::string type) : Name(name), Type(type) {}

void Zombie::announce(void) {
	std::cout << '<' << Name << " (" << Type << ")> Braiiiiiiinnnssss..." << std::endl;
}
