/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:09:59 by joopark           #+#    #+#             */
/*   Updated: 2021/05/18 18:43:51 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "Enemy.hpp"
#include <iostream>

class RadScorpion : public Enemy {
	public:
		RadScorpion();
		RadScorpion(const RadScorpion & radscorpion);
		RadScorpion & operator=(const RadScorpion & radscorpion);
		virtual ~RadScorpion();
		virtual void takeDamage(int damage);
};

#endif
