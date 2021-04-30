/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 02:01:31 by joopark           #+#    #+#             */
/*   Updated: 2021/04/29 23:59:49 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() : Soul() {}

Human::Human(Brain soul) : Soul(soul) {}

std::string Human::identify(void) const {
	return (Soul.identify());
}

const Brain& Human::getBrain(void) const {
	return (Soul);
}
