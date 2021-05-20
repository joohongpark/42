/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:55:03 by joopark           #+#    #+#             */
/*   Updated: 2021/05/19 01:33:54 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine : public ISpaceMarine {
	public:
		TacticalMarine();
		TacticalMarine(const TacticalMarine & tacticalmarine);
		TacticalMarine & operator=(const TacticalMarine & tacticalmarine);
		virtual ~TacticalMarine();
		virtual ISpaceMarine* clone(void) const;
		virtual void battleCry(void) const;
		virtual void rangedAttack(void) const;
		virtual void meleeAttack(void) const;
};

#endif
