/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:10:00 by joopark           #+#    #+#             */
/*   Updated: 2021/04/30 10:10:47 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA {
	private:
		Weapon weapon_;
		std::string name_;
	public:
		HumanA();
		void attack();
};

HumanA::HumanA(/* args */)
{
}

HumanA::~HumanA()
{
}


#endif