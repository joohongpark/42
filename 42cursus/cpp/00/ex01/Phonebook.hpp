/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:55:19 by joopark           #+#    #+#             */
/*   Updated: 2021/04/27 22:24:12 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include "PersonalData.hpp"

class Phonebook {
	private:
		PersonalData people[8];
		int index;
		int overwrite;
		void printcol(int i);
		void printpersonaldata(int i);
		void printall(void);
	public:
		Phonebook();
		void add(void);
		void search(void);
		void run(void);
};

#endif