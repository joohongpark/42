/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:49:42 by joopark           #+#    #+#             */
/*   Updated: 2021/05/18 15:26:48 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"
#include <iostream>

class PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle();
		PlasmaRifle(const PlasmaRifle & plasmarifle);
		PlasmaRifle & operator=(const PlasmaRifle & plasmarifle);
		virtual ~PlasmaRifle();
		virtual void attack(void) const;
};

#endif
