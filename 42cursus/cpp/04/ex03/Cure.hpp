/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:15:04 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 17:08:22 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure & cure);
		Cure & operator=(const Cure & cure);
		virtual ~Cure();
		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif
