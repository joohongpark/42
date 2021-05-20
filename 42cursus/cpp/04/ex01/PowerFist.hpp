/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:49:42 by joopark           #+#    #+#             */
/*   Updated: 2021/05/18 13:49:52 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"
#include <iostream>

class PowerFist : public AWeapon {
	public:
		PowerFist();
		PowerFist(const PowerFist & powerfist);
		PowerFist & operator=(const PowerFist & powerfist);
		virtual ~PowerFist();
		virtual void attack(void) const;
};

#endif
