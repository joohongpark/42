/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:04:02 by joopark           #+#    #+#             */
/*   Updated: 2021/05/19 02:28:03 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <cstddef>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad {
	private:
		int _listIdx;
		ISpaceMarine** _list;
	public:
		Squad();
		Squad(const Squad & squad);
		Squad & operator=(const Squad & squad);
		virtual ~Squad();
		virtual int getCount(void) const;
		virtual ISpaceMarine* getUnit(int idx) const;
		virtual int push(ISpaceMarine* ispacemarine);
};

#endif
