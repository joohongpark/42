/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:28:06 by joopark           #+#    #+#             */
/*   Updated: 2021/05/09 11:49:05 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include <ctime>

class FragTrap {
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