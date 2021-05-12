/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:28:03 by joopark           #+#    #+#             */
/*   Updated: 2021/05/11 20:13:43 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main (void) {
	std::string player1 = "joopark";
	std::string player2 = "hulk";
	std::string player3 = "ninja";
	std::string player4 = "clapclap";

	ClapTrap ct(60, 60, 120, 120, 1, player4, 60, 5, 0);
	FragTrap ft(player1);
	ScavTrap st(player2);
	NinjaTrap nt(player3);

	ft.takeDamage(3);
	st.takeDamage(1);
	nt.takeDamage(1);

	ft.beRepaired(2);
	st.beRepaired(2);
	nt.beRepaired(2);

	nt.rangedAttack(player2);

	st.meleeAttack(player1);

	nt.ninjaShoebox(ct);
	nt.ninjaShoebox(ft);
	nt.ninjaShoebox(st);
	nt.ninjaShoebox(nt);
	return (0);
}