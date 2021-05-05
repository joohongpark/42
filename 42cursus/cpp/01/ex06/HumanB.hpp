/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:10:00 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 01:04:33 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon *weapon_;
		std::string name_;
	public:
		HumanB();
		HumanB(std::string name);
		HumanB(std::string name, Weapon& weapon);
		void setWeapon(Weapon& weapon);
		void attack();
};

#endif
