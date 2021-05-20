/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:09:59 by joopark           #+#    #+#             */
/*   Updated: 2021/05/18 15:57:19 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"
#include <iostream>

class SuperMutant : public Enemy {
	public:
		SuperMutant();
		SuperMutant(const SuperMutant & supermutant);
		SuperMutant & operator=(const SuperMutant & supermutant);
		virtual ~SuperMutant();
};

#endif
