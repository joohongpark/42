/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 02:01:13 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 00:55:19 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : Status() {}

Brain::Brain(std::string status) : Status(status) {}

std::string Brain::identify(void) const {
	std::stringstream ss;

	ss << this;
	return (ss.str());
}
