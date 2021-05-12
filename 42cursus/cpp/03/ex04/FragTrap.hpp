/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:28:06 by joopark           #+#    #+#             */
/*   Updated: 2021/05/11 23:28:52 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <ctime>

class FragTrap : virtual public ClapTrap {
	private:
		unsigned int _rand_seed;
	public:
		FragTrap(std::string Name);
		FragTrap(const FragTrap& fragtrap);
		FragTrap& operator=(const FragTrap& fragtrap);
		~FragTrap();
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void vaulthunter_dot_exe(std::string const & target);
		void AK47Attack(std::string const & target);
		void RPG7Attack(std::string const & target);
		void ShotgunAttack(std::string const & target);
};

#endif