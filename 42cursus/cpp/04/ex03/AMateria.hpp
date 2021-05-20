/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:47:00 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 17:03:46 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
	protected:
		std::string _type;
		unsigned int _xp;
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria & amateria);
		AMateria & operator=(const AMateria & amateria);
		virtual ~AMateria();
		std::string const & getType(void) const;
		unsigned int getXP(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};

#endif
