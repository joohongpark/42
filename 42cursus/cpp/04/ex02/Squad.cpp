/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:04:08 by joopark           #+#    #+#             */
/*   Updated: 2021/05/19 12:18:25 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() : _listIdx(0), _list(NULL) {}

Squad::Squad(const Squad & squad) {
	if (this != &squad)
		*this = squad;
}

Squad & Squad::operator=(const Squad & squad) {
	if (this != &squad) {
		this->_listIdx = squad._listIdx;
		this->_list = new ISpaceMarine*[squad._listIdx];
		for (int i = 0; i < squad._listIdx; i++)
			this->_list[i] = squad._list[i];
	}
	return (*this);
}

Squad::~Squad() {
	for (int i = 0; i < _listIdx; i++)
		delete _list[i];
	delete [] _list;
}

int Squad::getCount(void) const {
	return (_listIdx);
}

ISpaceMarine* Squad::getUnit(int idx) const {
	return (_list[idx]);
}

int Squad::push(ISpaceMarine* ispacemarine) {
	ISpaceMarine** newList = new ISpaceMarine*[_listIdx + 1];
	for (int i = 0; i < _listIdx; i++)
		newList[i] = _list[i];
	newList[_listIdx] = ispacemarine;
	delete [] _list;
	_list = newList;
	return (_listIdx++);
}
