/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:28:06 by joopark           #+#    #+#             */
/*   Updated: 2021/05/09 22:41:59 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include <ctime>

class FragTrap {
	private:
		unsigned int _rand_seed;
		unsigned int _hit_points;
		unsigned int _max_hit_points;
		unsigned int _energy_points;
		unsigned int _max_energy_points;
		unsigned int _level;
		std::string _name;
		unsigned int _melee_attack_damage;
		unsigned int _ranged_attack_damage;
		unsigned int _armor_damage_reduction;
	public:
		FragTrap(std::string Name);
		FragTrap(const FragTrap& fragtrap);
		FragTrap& operator=(const FragTrap& fragtrap);
		~FragTrap();
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void vaulthunter_dot_exe(std::string const & target);
		void AK47Attack(std::string const & target);
		void RPG7Attack(std::string const & target);
		void ShotgunAttack(std::string const & target);
};

#endif