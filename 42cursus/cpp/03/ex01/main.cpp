/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:28:03 by joopark           #+#    #+#             */
/*   Updated: 2021/05/09 14:35:38 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main (void) {
	FragTrap ft1("joopark");
	ScavTrap ft2("puju");

	ft1.takeDamage(3);
	ft1.takeDamage(1);
	ft2.takeDamage(3);
	ft2.takeDamage(1);
	ft1.beRepaired(2);
	ft2.beRepaired(2);
	ft1.vaulthunter_dot_exe("puju");
	ft1.rangedAttack("puju");
	ft1.vaulthunter_dot_exe("puju");
	ft2.meleeAttack("joopark");
	ft1.vaulthunter_dot_exe("puju");
	ft1.vaulthunter_dot_exe("puju");
	ft2.challengeNewcomer("puju");
	ft2.challengeNewcomer("puju");
	return (0);
}