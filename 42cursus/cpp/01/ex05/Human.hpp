/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 02:01:34 by joopark           #+#    #+#             */
/*   Updated: 2021/04/29 23:59:53 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <sstream>
#include "Brain.hpp"

class Human {
	private:
		const Brain Soul;
	public:
		Human();
		Human(Brain soul);
		std::string identify(void) const;
		const Brain& getBrain(void) const;
};

#endif