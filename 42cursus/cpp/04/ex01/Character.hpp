/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:35:10 by joopark           #+#    #+#             */
/*   Updated: 2021/05/18 17:12:29 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <iostream>

class Character {
	private:
		int _ap;
		std::string _name;
		AWeapon* _aweapon;
	public:
		Character(std::string name);
		Character(const Character & character);
		Character & operator=(const Character & character);
		~Character();
		void equip(AWeapon* aweapon);
		void attack(Enemy* enemy);
		std::string getName(void) const;
		int getAP(void) const;
		bool isEquip(void) const;
		std::string getWeaponName(void) const;
};

std::ostream &operator<<(std::ostream &out, const Character & character);

#endif
