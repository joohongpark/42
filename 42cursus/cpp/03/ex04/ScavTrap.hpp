/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:18:16 by joopark           #+#    #+#             */
/*   Updated: 2021/05/11 16:57:17 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <ctime>

class ScavTrap : public ClapTrap {
	private:
		unsigned int _rand_seed;
	public:
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap& fragtrap);
		ScavTrap& operator=(const ScavTrap& fragtrap);
		~ScavTrap();
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void challengeNewcomer(std::string const & target);
};

#endif