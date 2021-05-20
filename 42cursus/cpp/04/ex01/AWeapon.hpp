/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 09:44:36 by joopark           #+#    #+#             */
/*   Updated: 2021/05/18 12:55:12 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <string>

class AWeapon {
	protected:
		std::string _name;
		int _apcost;
		int _damage;
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(const AWeapon & aweapon);
		AWeapon & operator=(const AWeapon & aweapon);
		virtual ~AWeapon();
		std::string getName(void) const;
		int getAPCost(void) const;
		int getDamage(void) const;
		virtual void attack(void) const = 0;
};

#endif
