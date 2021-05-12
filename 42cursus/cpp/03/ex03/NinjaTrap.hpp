/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:44:11 by joopark           #+#    #+#             */
/*   Updated: 2021/05/11 19:46:29 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {
	public:
		NinjaTrap(std::string Name);
		NinjaTrap(const NinjaTrap& fragtrap);
		NinjaTrap& operator=(const NinjaTrap& fragtrap);
		~NinjaTrap();
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void ninjaShoebox(ClapTrap& target);
		void ninjaShoebox(FragTrap& target);
		void ninjaShoebox(ScavTrap& target);
		void ninjaShoebox(NinjaTrap& target);
};

#endif