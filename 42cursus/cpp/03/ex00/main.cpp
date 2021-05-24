/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:28:03 by joopark           #+#    #+#             */
/*   Updated: 2021/05/09 23:37:21 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main (void) {
	std::string player1 = "joopark";
	std::string player2 = "hulk";
	FragTrap ft1(player1);
	FragTrap ft2(player2);

	ft1.takeDamage(3);
	ft1.takeDamage(1);

	ft2.takeDamage(3);
	ft2.takeDamage(1);

	ft1.beRepaired(2);
	ft2.beRepaired(2);

	ft1.rangedAttack(player2);

	ft2.meleeAttack(player1);

	ft1.vaulthunter_dot_exe(player2);
	ft1.vaulthunter_dot_exe(player2);
	ft1.vaulthunter_dot_exe(player2);
	ft1.vaulthunter_dot_exe(player2);
	ft2.vaulthunter_dot_exe(player1);
	ft2.vaulthunter_dot_exe(player1);
	ft2.vaulthunter_dot_exe(player1);
	ft2.vaulthunter_dot_exe(player1);
	return (0);
}