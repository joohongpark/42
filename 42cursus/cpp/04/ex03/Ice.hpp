/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:28:31 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 17:08:38 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice & ice);
		Ice & operator=(const Ice & ice);
		virtual ~Ice();
		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif
