/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:30:10 by joopark           #+#    #+#             */
/*   Updated: 2021/05/25 12:43:22 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <ctime>

struct Data {
	std::string * stringOne;
	int integer;
	std::string * stringTwo;
};

void * serialize(void);
Data * deserialize(void * raw);

#endif
