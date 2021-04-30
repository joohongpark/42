/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 02:01:13 by joopark           #+#    #+#             */
/*   Updated: 2021/04/29 23:55:16 by joopark          ###   ########.fr       */
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