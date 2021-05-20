/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:17:15 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 16:03:55 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		AMateria* _m[4];
		std::string _name;
	public:
		Character(std::string const & name);
		Character(const Character & character);
		Character & operator=(const Character & character);
		virtual ~Character();
		virtual std::string const & getName(void) const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
