/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:30:17 by joopark           #+#    #+#             */
/*   Updated: 2021/05/20 02:23:41 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _m[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource & materiasource);
		MateriaSource & operator=(const MateriaSource & materiasource);
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria* amateria);
		virtual AMateria* createMateria(std::string const & type);
};

#endif
