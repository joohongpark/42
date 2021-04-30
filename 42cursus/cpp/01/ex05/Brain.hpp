/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 02:01:29 by joopark           #+#    #+#             */
/*   Updated: 2021/04/29 23:55:11 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <sstream>

class Brain {
	private:
		std::string Status;
	public:
		Brain();
		Brain(std::string status);
		std::string identify(void) const;
};

#endif