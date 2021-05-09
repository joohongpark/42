/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:18:16 by joopark           #+#    #+#             */
/*   Updated: 2021/05/09 14:26:20 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include <ctime>

class ScavTrap {
	private:
		unsigned int _rand_seed; // rand seed
		unsigned int _hit_points; // HP
		unsigned int _max_hit_points; // HP 최댓값
		unsigned int _energy_points; // 스킬 쓰기위한 포인트
		unsigned int _max_energy_points; // 포인트 최댓값
		unsigned int _level; // 레벨
		std::string _name;
		unsigned int _melee_attack_damage; // 근접 공격 데미지
		unsigned int _ranged_attack_damage; // 원거리 공격 데미지
		unsigned int _armor_damage_reduction; // 감소값
	public:
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap& fragtrap);
		ScavTrap& operator=(const ScavTrap& fragtrap);
		~ScavTrap();
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void challengeNewcomer(std::string const & target);
};

#endif