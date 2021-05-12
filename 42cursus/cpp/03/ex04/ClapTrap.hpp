/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:51:07 by joopark           #+#    #+#             */
/*   Updated: 2021/05/11 19:43:50 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
	protected:
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
		ClapTrap(	unsigned int hit_points,
					unsigned int max_hit_points,
					unsigned int energy_points,
					unsigned int max_energy_points,
					unsigned int level,
					std::string name,
					unsigned int melee_attack_damage,
					unsigned int ranged_attack_damage,
					unsigned int armor_damage_reduction	);
		ClapTrap(const ClapTrap& fragtrap);
		ClapTrap& operator=(const ClapTrap& fragtrap);
		~ClapTrap();
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void);
};

#endif